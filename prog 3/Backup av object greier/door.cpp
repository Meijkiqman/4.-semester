#include "door.h"

Door::Door()
{
    mVertices.push_back(Vertex(0.2f, 0, 0, 1, 1, 1));
    mVertices.push_back(Vertex(0.2f, 0.5, 0, 1, 1, 1));
    mVertices.push_back(Vertex(-0.2f, 0.5, 0, 1, 1, 1));

    mVertices.push_back(Vertex(0.2f, 0, 0, 1, 1, 1));
    mVertices.push_back(Vertex(-0.2f, 0.5, 0, 1, 1, 1));
    mVertices.push_back(Vertex(-0.2f, 0, 0, 1, 1, 1));


    mMatrix.setToIdentity();
}

void Door::init(GLint matrixUniform)
{
    VisualObject::init(matrixUniform);
}

void Door::draw()
{
    VisualObject::draw();
}

void Door::OpenDoor()
{
}