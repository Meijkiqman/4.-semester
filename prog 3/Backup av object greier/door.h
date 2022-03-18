
#pragma once

#include "visualobject.h"
class Door : public VisualObject
{
public:
	Door();
	virtual void init(GLint matrixUniform) override;
	virtual void draw() override;
	void OpenDoor();
	bool bIsOpen = false;

};
