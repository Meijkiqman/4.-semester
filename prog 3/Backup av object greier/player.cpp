#include "player.h"

Player::Player()
{
    //Create verts
    //1
    mVertices.push_back(Vertex(0.5, 0.5, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(0.5, -0.5, 0.5, 1, 0, 0));
    mVertices.push_back(Vertex(-0.5, -0.5, 0.5, 1, 0, 0));

    mVertices.push_back(Vertex(-0.5, -0.5, 0.5, 0, 1, 0));
    mVertices.push_back(Vertex(-0.5, 0.5, 0.5, 0, 1, 0));
    mVertices.push_back(Vertex(0.5, 0.5, 0.5, 0, 1, 0));

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

void Player::init(GLint matrixUniform)
{
    VisualObject::init(matrixUniform);
}

void Player::draw()
{
    VisualObject::draw();
}
