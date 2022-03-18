
#ifndef PLAYER_H
#define PLAYER_H
#include "visualobject.h"
class Player : public VisualObject
{
public:
	Player();
	void init(GLint matrixUniform) override;
	void draw() override;

};
#endif
