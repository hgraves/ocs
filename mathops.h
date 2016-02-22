#ifndef MATHOPS_H
#define MATHOPS_H

#include "mytypes.h"
#include <iostream>

class mathops_class {
public:
	const static double PI = 3.141592653;

	double dot(vect_t vec1, vect_t vec2);
	vect_t cross(vect_t vec1, vect_t vec2);
	double HMStoDEG(int hour, int min, double sec);
	double DEGtoRAD(double deg);
	double RADtoDEG(double rad);
	double returnFraction(double val);
	vect_t range(vect_t observer, vect_t target);

private:

};

#endif