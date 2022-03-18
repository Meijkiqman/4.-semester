#include "outside.h"
#include "house.h"
#include "plane.h"
#include "renderwindow.h"
#include "quadtree.h"
#include "trophy.h"
#include "player.h"
#include "door.h"

OutsideScene::OutsideScene(RenderWindow* rWindow) : Scene(rWindow)
{
	//Create camera for every scene instead 
	mCamera = new Camera;
	//creates the house
	mMap.insert(std::pair<std::string, VisualObject*>{"House", new House()});
	mMap["House"]->SetScale(QVector3D(5, 5, 5));
	mMap["House"]->SetPosition(QVector3D(0, 0, 4));
	mMap["House"]->SetRotation(QVector3D(1, 0, 0));


	//creates plane that acts as ground
	mMap.insert(std::pair<std::string, VisualObject*>{"ground", new Plane()});

	//creates and places trophies randomly on the map
	for (int i = 0; i < 7; i++) 
	{
		mMap.insert(std::pair<std::string, VisualObject*>{ std::string("Trophy" + i), new Trophy()});
		mMap[std::string("Trophy" + i)]->SetPosition(QVector3D(std::rand() % 20, std::rand() % 20, 0.5));
	}

	//Create palyer
	mMap.insert(std::pair<std::string, VisualObject*>{"Player", new Player()});
	mMap["Player"]->SetPosition(QVector3D(0, -5, 1));

	//Create door
	mMap.insert(std::pair<std::string, VisualObject*>{"door", new Door()});

	
	gsml::Point2D a{ 10,10 }; //ne
	gsml::Point2D b{ -10,10 }; //nw
	gsml::Point2D c{ 10,-10 }; //se
	gsml::Point2D d{ -10,-10 }; //sw
	//Se, sw, ne, nw
	mQuadTree.init(c, d, a, b);
	//uses quadtree to check whre to player is located
	mQuadTree.subDivide(6);
	for (auto it = mMap.begin(); it != mMap.end(); it++) 
	{
		mQuadTree.insert((*it).second->getPosition2D(), (*it).first, (*it).second);
	}
}

OutsideScene::~OutsideScene()
{

}
void OutsideScene::init(GLint matrixUniform)
{
	for (auto it = mMap.begin(); it != mMap.end(); it++) 
	{
		(*it).second->init(matrixUniform);
	}
}

//render function moved from renderwindow to here for easier management
void OutsideScene::render(GLint mPMatrixUniform, GLint mVMatrixUniform)
{
	mCamera->init(mPMatrixUniform, mVMatrixUniform);

	mCamera->perspective(90, mRenderWindow->width() / mRenderWindow->height(), 0.1, 1000.0); // verticalAngle, aspectRatio, nearPlane,farPlane

	mCamera->lookAt(QVector3D{ 0,-10,5 }, QVector3D{ 0,0,0 }, QVector3D{ 0,1,0 });
	//mCamera->translate(0,0,-2);
	mCamera->rotate(0, 0.1f, 0);
	mCamera->update();

	if (true) 
	{
		gsml::QuadTree<std::string, VisualObject*>* temp = mQuadTree.find(mMap["Player"]->getPosition2D());
		//Iterate trough the objects in the quad
		for (auto it = temp->begin(); it != temp->end(); it++) {
			//Check if it a door
			Trophy* trophy = dynamic_cast<Trophy*>(*it);
			if (trophy) {
				//Open the scene
				trophy->PickupTrophy();
			}
		}
	}

	for (auto it = mMap.begin(); it != mMap.end(); it++) 
	{
		(*it).second->UpdateTransform();
		(*it).second->draw();
	}
}

void OutsideScene::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_E)
	{
		//Get quad the player is in 
		gsml::QuadTree<std::string, VisualObject*>* temp = mQuadTree.find(mMap["Player"]->getPosition2D());
		//Iterate trough the objects in the quad
		for (auto it = temp->begin(); it != temp->end(); it++) {
			//Check if it a door
			if ((*it) == mMap["Door"]) 
			{
				//Open the scene
				mRenderWindow->NextScene();
			}
		}
	}
	if (event->key() == Qt::Key_W)
	{
		mMap["Player"]->move(0, 0.1f, 0);
	}
	if (event->key() == Qt::Key_S)
	{
		mMap["Player"]->move(0, -0.1f, 0);
	}
	if (event->key() == Qt::Key_A)
	{
		mMap["Player"]->move(-0.1f, 0, 0);
	}
	if (event->key() == Qt::Key_D)
	{
		mMap["Player"]->move(0.1f, 0, 0);
	}
}