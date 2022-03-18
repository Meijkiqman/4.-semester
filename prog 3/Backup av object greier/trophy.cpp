#include "trophy.h"

Trophy::Trophy()
{
	OctahedronBall(3);
}

Trophy::~Trophy()
{

}

void Trophy::init(GLint matrixUniform)
{
	OctahedronBall::init(matrixUniform);
}

void Trophy::draw()
{
	if (bDraw) {
		OctahedronBall::draw();
	}
}

void Trophy::PickupTrophy()
{
	bDraw = false;
}