
#ifndef SCENE_H
#define SCENE_H

#include <unordered_map>
#include "visualobject.h"
#include "camera.h"
#include "quadtree.h"
#include "qevent.h"

class RenderWindow;

//klasse for scener, kan bytte scener on the go istenfor å bytte ut varibler hver gang
class Scene
{
public:
	Scene(RenderWindow* rWindow);
	~Scene();

	virtual void init(GLint matrixUniform);
	virtual void render(GLint mPMatrixUniform, GLint mVMatrixUniform);

	//Input
	virtual void keyPressEvent(QKeyEvent* event);
protected:
	//Referanse til render window for kamera
	RenderWindow* mRenderWindow;
	//Alt som renders i Map
	std::unordered_map<std::string, VisualObject*> mMap;
	//Quadtre
	gsml::QuadTree<std::string, VisualObject*> mQuadTree;
	//Kamera referanse
	Camera* mCamera;

	std::unordered_map<int, bool> mKeyboard;
};
#endif //SCENE_H