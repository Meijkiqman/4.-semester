#ifndef HOUSE_H
#define HOUSE_H


#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"
#include "visualobject.h"
class House : public VisualObject
{
public:
    House();
    virtual void init(GLint matrixUniform) override;
    virtual void draw() override;
};

#endif // HOUSE_H