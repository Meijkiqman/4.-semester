#include "npc.h"
#include "renderwindow.h"
#include "visualpoint.h"
#include "quadtraticpolynomial.h"
#include "cubicpolynomial.h"
#include "beziercurve.h"
#include "cube.h"
#include "quadtree.h"

NPCScene::NPCScene(RenderWindow* rWindow) : Scene(rWindow)
{
    //Matte oblig 2 3.4.6
    mMap.insert(std::pair<std::string, VisualObject*>{"QuadtraticPolynomial", new QuadtraticPolynomial(-0.012024466, -0.029310073f, 5.856566423f, 0.1f)});
    std::vector<Vertex> points;
    points.push_back(Vertex{ 3, 10, 0 });
    points.push_back(Vertex{ 1, 6.5, 0 });
    points.push_back(Vertex{ -5.9, 7.6, 0 });
    points.push_back(Vertex{ -3, 5, 0 });
    points.push_back(Vertex{ -2, 1.7, 0 });
    points.push_back(Vertex{ -7, 4.3, 0 });
    points.push_back(Vertex{ 6.9, 4.2, 0 });
    points.push_back(Vertex{ 3.8, 5.2, 0 });

    for (auto i = 0; i < points.size(); i++)
    {
        mMap.insert(std::pair<std::string, VisualObject*>{ std::to_string(i), new VisualPoint(points)});
    }

    //Matte oblig 2 4.6.7
  mMap.insert(std::pair<std::string, VisualObject*>{"CubicPolynomial", new CubicPolynomial(-0.78, 0.69, -0.49, 0.54, 0.1f)});
   std::vector<Vertex> points2;
   points2.push_back(Vertex{ 0.9f, 0.6f, 0 });
   points2.push_back(Vertex{ 2.6f, -1.1f, 0 });
   points2.push_back(Vertex{ 3.5f, 3.7f, 0 });
   points2.push_back(Vertex{ 6.9f, 4.2, 0 });

   for (auto i = 0; i < points2.size(); i++)
   {
       mMap.insert(std::pair<std::string, VisualObject*>{ std::to_string(i * 10), new VisualPoint(points2)});
   }

   //bezier curve
   std::vector<QVector3D> controlPoints;
   controlPoints.push_back(QVector3D(0.f, 0.f, 0.f));
   controlPoints.push_back(QVector3D(2.f, 3.f, 0.f));
   controlPoints.push_back(QVector3D(4.f, -3.f, 0.f));
   controlPoints.push_back(QVector3D(6.f, 3.f, 0.f));
   mMap.insert(std::pair<std::string, VisualObject*>{"BezierCurve", new BezierCurve(controlPoints)});

   mMap.insert(std::pair<std::string, VisualObject*>{"NPC", new Cube()});
  // mMap.insert(std::pair<std::string, VisualObject*>{"Cube 1", new Cube()});
   mCamera = new Camera;

}

void NPCScene::init(GLint matrixUniform)
{
    for (auto it = mMap.begin(); it != mMap.end(); it++) 
    {
        (*it).second->init(matrixUniform);
    }
}

void NPCScene::render(GLint mPMatrixUniform, GLint mVMatrixUniform)
{
    mCamera->init(mPMatrixUniform, mVMatrixUniform);

    mCamera->perspective(90, mRenderWindow->width() / mRenderWindow->height(), 0.1, 10000.0); // verticalAngle, aspectRatio, nearPlane,farPlane

    mCamera->lookAt(QVector3D{ 0,-10,5 }, QVector3D{ 0,0,0 }, QVector3D{ 0,1,0 });
    //mCamera->translate(0,0,-2);
    mCamera->rotate(0, 0.1f, 0);
    mCamera->update();

    mMap["NPC"]->SetPosition(QVector3D(0, 0, 0));
    //What direction should the NPC move
    float dir = 1;
    //Get the x coordinate of NPC

    float x = mMap["NPC"]->GetPosition().column(3).x();

    //Decide if the direction should be left or right
    if (x >= 10)
    {
        goRight = false;
    }
    else if (x <= -10) 
    {
        goRight = true;
    }
    if (goRight) 
    {
        dir = 1;
    }
    else 
    {
        dir = -1;
    }
    dir *= 0.01f;


    float y = 0;
    if (bUseQuadtratic) 
    {
        //Get the the y from the quadtratic polynomial class
        QuadtraticPolynomial* quad = dynamic_cast<QuadtraticPolynomial*>(mMap["QuadtraticPolynomial"]);
        y = quad->GetYPos(mMap["NPC"]->GetPosition().column(3).x());
    }
    else 
    {
        CubicPolynomial* quad = dynamic_cast<CubicPolynomial*>(mMap["CubicPolynomial"]);
        y = quad->GetYPos(mMap["NPC"]->GetPosition().column(3).x());
    }

    //Add x to the x pos, and set y pos 
    mMap["NPC"]->SetPosition(QVector3D(mMap["NPC"]->GetPosition().column(3).x() + dir, y, 0));
    //mMap["NPC"]->SetPosition(QVector3D(0, 0, 0));
    for (auto it = mMap.begin(); it != mMap.end(); it++)
    {
        (*it).second->UpdateTransform();
        (*it).second->draw();
    }
}

void NPCScene::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_W)
    {
        bUseQuadtratic = !bUseQuadtratic;
    }
}