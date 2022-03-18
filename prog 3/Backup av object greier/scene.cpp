
#include "scene.h"
#include "renderwindow.h"

Scene::Scene(RenderWindow* rWindow) : mRenderWindow(rWindow)
{
}

Scene::~Scene()
{
}

void Scene::init(GLint matrixUniform)
{
	//Base klasse for alle scener

}

void Scene::render(GLint mPMatrixUniform, GLint mVMatrixUniform)
{
	//Base klasse for alle scner
}

void Scene::keyPressEvent(QKeyEvent* event)
{

}
