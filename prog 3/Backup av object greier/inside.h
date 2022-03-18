#pragma once
#include "scene.h"
class InsideScene : public Scene
{
public:
	InsideScene(RenderWindow* rWindow);
	~InsideScene();

	virtual void init(GLint matrixUniform) override;
	virtual void render(GLint mPMatrixUniform, GLint mVMatrixUniform) override;

	virtual void keyPressEvent(QKeyEvent* event) override;
};
