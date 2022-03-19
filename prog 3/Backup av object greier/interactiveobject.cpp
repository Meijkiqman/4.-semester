#include "interactiveobject.h"

InteractiveObject::InteractiveObject()
{

}

InteractiveObject::~InteractiveObject(){

}

void InteractiveObject::init(GLint matrixUniform){

}

void InteractiveObject::draw(){

}

void InteractiveObject::move(float x, float y, float z){
    mx += x;
    my += y;
    mz += z;
}
