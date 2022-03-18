#ifndef GRAPH_H
#define GRAPH_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"
#include "cube.h"
#include "visualobject.h"

class Graph : public VisualObject
{
public:
    Graph();
    //~Graph();
    virtual void init(GLint matrixUniform) override;
    virtual void draw() override;
    Vertex getVert(float x);
   // void drawPoints();
   // void setPoints();
   // void readFile(std::string filename);
   // void writeFile(float func(float x), std::string filename);
   // void writeFile(Vector3D func(float x, std::vector<Vector3D> y), std::string filename);
   //
   // void moveNPC(float func(float x));

protected:
   // Cube* mNPC{ nullptr };
   // float mNPCSpeed{ 0.1f };
    float mNPCLocationX{ 0.f };

   //int mVertCount{ 0 };
   //
   //float startValue{ -10.f };
   //float endValue{ 10.f };
   //
   //std::vector<Vector3D> points;

};

#endif // GRAPH_H
