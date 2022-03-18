
#ifndef TROPHY_H
#define TROPHY_H

#include "octahedronball.h"
class Trophy : public OctahedronBall
{
public:
	Trophy();
	~Trophy();
	void init(GLint matrixUniform) override;
	void draw() override;
	void PickupTrophy();
	bool bDraw = true;
};
#endif // TROPHY_H