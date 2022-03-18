#include "inside.h"
#include "house.h"
#include "plane.h"
#include "renderwindow.h"
#include "door.h"
#include "player.h"

InsideScene::InsideScene(RenderWindow* rWindow) : Scene(rWindow)
{
	//Create camera
	mCamera = new Camera;
	//Create the house
	mMap.insert(std::pair<std::string, VisualObject*>{"House", new House()});
	mMap["House"]->SetScale(QVector3D(5, 5, 5));
	mMap["House"]->SetPosition(QVector3D(0, 0, 4));
	mMap["House"]->SetRotation(QVector3D(1, 0, 0));
	
	//create door :)
	mMap.insert(std::pair<std::string, VisualObject*>{"door", new Door()});

	//Create floor, 
	mMap.insert(std::pair<std::string, VisualObject*>{"ground", new Plane()});

	//creates player
	mMap.insert(std::pair<std::string, VisualObject*>{"Player", new Player()});
	mMap["Player"]->SetPosition(QVector3D(0, -1, 1));

	gsml::Point2D a{ 10,10 }; //ne
	gsml::Point2D b{ -10,10 }; //nw
	gsml::Point2D c{ 10,-10 }; //se
	gsml::Point2D d{ -10,-10 }; //sw
	//Se, sw, ne, nw
	mQuadTree.init(c, d, a, b);
	mQuadTree.subDivide(3);

	for (auto it = mMap.begin(); it != mMap.end(); it++) 
	{
		mQuadTree.insert((*it).second->getPosition2D(), (*it).first, (*it).second);
	}
}

InsideScene::~InsideScene()
{
}

void InsideScene::init(GLint matrixUniform)
{
	for (auto it = mMap.begin(); it != mMap.end(); it++) 
	{
		(*it).second->init(matrixUniform);
	}
}

void InsideScene::render(GLint mPMatrixUniform, GLint mVMatrixUniform)
{
	mCamera->init(mPMatrixUniform, mVMatrixUniform);

	mCamera->perspective(90, mRenderWindow->width() / mRenderWindow->height(), 0.1, 100.0); // verticalAngle, aspectRatio, nearPlane,farPlane

	mCamera->lookAt(QVector3D{ -2,-2,5 }, QVector3D{ 0,0,0 }, QVector3D{ 0,1,0 });
	//mCamera->translate(0,0,-2);
	mCamera->rotate(20, 0.1f, 0);
	mCamera->update();

	for (auto it = mMap.begin(); it != mMap.end(); it++) 
	{
		(*it).second->UpdateTransform();
		(*it).second->draw();
	}
}

void InsideScene::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_E)
	{
		//Get quad the player is in 
		gsml::QuadTree<std::string, VisualObject*>* temp = mQuadTree.find(mMap["Player"]->getPosition2D());
		//Iterate trough the objects in the quad
		for (auto it = temp->begin(); it != temp->end(); it++) {
			//Check if it a door
			if ((*it) == mMap["Door"]) {
				//Open the scene
				//mRenderWindow->NextScene();
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
