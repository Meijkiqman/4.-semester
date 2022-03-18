
#include "plane.h"

Plane::Plane()
{
    construct();
    mMatrix.setToIdentity();
}

Plane::~Plane()
{
}

void Plane::init(GLint matrixUniform){
    VisualObject::init(matrixUniform);
}

void Plane::draw(){
    VisualObject::draw();
}

void Plane::construct()
{
	for (float i{ -20 }; i < 20; ++i)
		for (float j{ -20 }; j < 20; ++j)
		{
			drawRectangle(QVector2D(1.f * i, 1.f * j), 1.f, 1.f);
		}
}

void Plane::drawRectangle(QVector2D bottomLeft, float width, float height)
{
	GLuint indices = mVertices.size();

	mVertices.push_back(Vertex(bottomLeft.x(), bottomLeft.y(), 0.f, 0, 1, 0));
	mVertices.push_back(Vertex(bottomLeft.x() + width, bottomLeft.y(), 0.f, 0, 1, 0));
	mVertices.push_back(Vertex(bottomLeft.x() + width, bottomLeft.y() + height, 0.f, 0, 1, 0));
	mVertices.push_back(Vertex(bottomLeft.x(), bottomLeft.y() + height, 0.f, 0, 0, 0));

	GLuint tempIndices[4];
	for (int i{}; i < 4; ++i)
	{
		tempIndices[i] = std::max(static_cast<int>(indices), 0) + i;
	}

	mIndices.push_back(tempIndices[0]);
	mIndices.push_back(tempIndices[1]);
	mIndices.push_back(tempIndices[2]);

	mIndices.push_back(tempIndices[2]);
	mIndices.push_back(tempIndices[3]);
	mIndices.push_back(tempIndices[0]);
}