#pragma once
#include "scene.h"
class OutsideScene : public Scene
{
public:
	OutsideScene(RenderWindow* rWindow);
	~OutsideScene();

	virtual void init(GLint matrixUniform) override;
	virtual void render(GLint mPMatrixUniform, GLint mVMatrixUniform) override;

	virtual void keyPressEvent(QKeyEvent* event) override;
};
