#include "graph.h"
#include <iostream>
#include <fstream>

Graph::Graph()
{
	float length = 10;
	float step = 0.1f;
	for (float i = 0; i < length; i+= step)
    {
		mVertices.push_back(getVert(i));
	}
}

Vertex Graph::getVert(float x)
{
    //Oblig 2 funksjon
    float y = pow(6.9f * x, 2) + 1.3f * x + 3.2f;
    Vertex v{ x, y, 0, 1, 0,0 };

    return v;
}

void Graph::init(GLint matrixUniform)
{

    mNPCLocationX = mVertices[0].x;
    mMatrixUniform = matrixUniform;

    initializeOpenGLFunctions();

    //Vertex Array Object - VAO
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);

    glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(Vertex), mVertices.data(), GL_STATIC_DRAW);

    // 1rst attribute buffer : vertices
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // 2nd attribute buffer : colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void Graph::draw()
{
	initializeOpenGLFunctions();
	glBindVertexArray(mVAO);
	glUniformMatrix4fv(mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
	glDrawArrays(GL_LINES, 0, mVertices.size());
}


