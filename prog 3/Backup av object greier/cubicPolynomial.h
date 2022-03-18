#ifndef CUBICPOLYNOM_H
#define CUBICPOLYNOM_H

#include "visualcurve.h"

class CubicPolynomial : public VisualCurve
{
public:
	CubicPolynomial(double a, double b, double c, double d, float dx);
	~CubicPolynomial();
	float GetYPos(float x);
	float ma, mb, mc, md;
private:
	double p(double a, double b, double c, double d, double x);
};

#endif // KUBISKPOLYNOM_H