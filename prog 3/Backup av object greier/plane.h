#ifndef PLANE_H
#define PLANE_H
//surface for olbig2
#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include "visualobject.h"
#include "vertex.h"
class Plane : public VisualObject
{
public:

    Plane();
   // Plane(std::string filename);
    ~Plane();
    virtual void init(GLint matrixUniform) override;
    virtual void draw() override;
    void construct();
    void drawRectangle(QVector2D bottomLeft, float width, float height);
};

#endif // PLANE_H
