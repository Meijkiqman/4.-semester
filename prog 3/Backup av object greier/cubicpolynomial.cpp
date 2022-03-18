#include "cubicpolynomial.h"

CubicPolynomial::CubicPolynomial(double a, double b, double c, double d, float dx)
{

    for (auto x = -10.f; x <= 10; x += 0.1)
    {
        auto y = p(a, b, c, d, x);
        mVertices.push_back(Vertex(x, y, 0, 0, 1, 0));
    }
    mMatrix.setToIdentity();

}

CubicPolynomial::~CubicPolynomial()
{
}

double CubicPolynomial::p(double a, double b, double c, double d, double x)
{
    return a * x * x * x + b * x * x + c * x + d;

}

float CubicPolynomial::GetYPos(float x) 
{
    return p(ma, mb, mc, md, x);
}