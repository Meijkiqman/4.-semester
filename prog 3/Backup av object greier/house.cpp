
#include "house.h"
#include "vertex.h"

House::House()
{
   
    //Front
    //1
    mVertices.push_back(Vertex(0.5, -0.5, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(0.5, 0, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(0.2, 0, 0.5, 1, 0, 0));
    //2
    mVertices.push_back(Vertex(0.5, -0.5, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(0.2, 0, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(0.2, -0.5, 0.5, 1, 0, 0));
    //3
    mVertices.push_back(Vertex(0.5, 0, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(0.5, 0.5, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(0.2, 0, 0.5, 1, 0, 0));
    //4
    mVertices.push_back(Vertex(0.5, 0.5, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(0.2, 0.5, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(0.2, 0, 0.5, 1, 0, 0));
    //5
    mVertices.push_back(Vertex(0.2, 0, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(0.2, 0.5, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(-0.2, 0, 0.5, 1, 0, 0));
    //6
    mVertices.push_back(Vertex(-0.2, 0, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(0.2, 0.5, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(-0.2, 0.5, 0.5, 1, 0, 0));
    //7
    mVertices.push_back(Vertex(-0.2, 0, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(-0.2, 0.5, 0.5, 0, 0));
    mVertices.push_back(Vertex(-0.5, 0.5, 0.5, 1, 0, 0));
    //8
    mVertices.push_back(Vertex(-0.2, 0, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(-0.5, 0, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(-0.5, 0.5, 0.5, 1, 0, 0));
    //9
    mVertices.push_back(Vertex(-0.2, 0, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(-0.5, 0, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(-0.5, -0.5, 0.5, 1, 0, 0));
    //10
    mVertices.push_back(Vertex(-0.2, 0, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(-0.5, -0.5, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(-0.2, -0.5, 0.5, 1, 0, 0));


    //2
    mVertices.push_back(Vertex(0.5, 0.5, -0.5, 0, 0, 1));
    mVertices.push_back(Vertex(0.5, -0.5, -0.5, 0, 0, 1));
    mVertices.push_back(Vertex(-0.5, -0.5, -0.5, 0, 0, 1));

    mVertices.push_back(Vertex(-0.5, -0.5, -0.5, 1, 1, 0));
    mVertices.push_back(Vertex(-0.5, 0.5, -0.5, 1, 1, 0));
    mVertices.push_back(Vertex(0.5, 0.5, -0.5, 1, 1, 0));

    //3
    mVertices.push_back(Vertex(0.5, 0.5, 0.5, 1, 0, 1));
    mVertices.push_back(Vertex(0.5, -0.5, 0.5, 1, 0, 1));
    mVertices.push_back(Vertex(0.5, 0.5, -0.5, 1, 0, 1));

    mVertices.push_back(Vertex(0.5, -0.5, -0.5, 0, 1, 1));
    mVertices.push_back(Vertex(0.5, -0.5, 0.5, 0, 1, 1));
    mVertices.push_back(Vertex(0.5, 0.5, -0.5, 0, 1, 1));

    //4
    mVertices.push_back(Vertex(-0.5, -0.5, -0.5, 0.5, 0.4, 0.1));
    mVertices.push_back(Vertex(-0.5, 0.5, -0.5, 0.5, 0.4, 0.1));
    mVertices.push_back(Vertex(-0.5, -0.5, 0.5, 0.5, 0.4, 0.1));

    mVertices.push_back(Vertex(-0.5, 0.5, 0.5, 0.1, 0.4, 0.5));
    mVertices.push_back(Vertex(-0.5, 0.5, -0.5, 0.1, 0.4, 0.5));
    mVertices.push_back(Vertex(-0.5, -0.5, 0.5, 0.1, 0.4, 0.5));

    //Adam
    mVertices.push_back(Vertex(0.5, -0.5, 0.5, 0.956, 0.741, 1));
    mVertices.push_back(Vertex(-0.5, -0.5, 0.5, 0.956, 0.741, 1));
    mVertices.push_back(Vertex(0.5, -0.5, -0.5, 0.956, 0.741, 1));

    mVertices.push_back(Vertex(-0.5, -0.5, -0.5, 0.956, 1, 0.741));
    mVertices.push_back(Vertex(-0.5, -0.5, 0.5, 0.956, 1, 0.741));
    mVertices.push_back(Vertex(0.5, -0.5, -0.5, 0.956, 1, 0.741));

    //Top
    mVertices.push_back(Vertex(0.5, 0.5, 0.5, 0.546, 0.5454, 0.23));
    mVertices.push_back(Vertex(-0.5, 0.5, 0.5, 0.546, 0.5454, 0.23));
    mVertices.push_back(Vertex(0.5, 0.5, -0.5, 0.546, 0.5454, 0.23));

    mVertices.push_back(Vertex(-0.5, 0.5, -0.5, 0.98, 0.34, 0.23));
    mVertices.push_back(Vertex(-0.5, 0.5, 0.5, 0.98, 0.34, 0.23));
    mVertices.push_back(Vertex(0.5, 0.5, -0.5, 0.98, 0.34, 0.23));

    mMatrix.setToIdentity();
}

void House::init(GLint matrixUniform) 
{

    VisualObject::init(matrixUniform);
    mMatrix.scale(2);
}

void House::draw()
{
    VisualObject::draw();
}