#pragma once
#include "scene.h"
class NPCScene : public Scene
{
public:
	NPCScene(RenderWindow* rWindow);
	virtual void init(GLint matrixUniform) override;
	virtual void render(GLint mPMatrixUniform, GLint mVMatrixUniform) override;

	virtual void keyPressEvent(QKeyEvent* event) override;
	bool goRight = true;
	bool bUseQuadtratic = false;
};