#include "mathops.h"
#include <stdio.h>
#include <math.h>
#include <iostream>

/*************************************************************************
/** @brief returns the fractional part of a number
 *
 *		@param	val			number to be converted
 *
 *		@return	fractional part of val
 *
 *		@notes	none
 *
 *************************************************************************/
 double mathops_class::returnFraction(double val) {

	return(val -(int)val);

}

double mathops_class::RADtoDEG(double rad) {

	return(rad * 180.0/PI);
}

double mathops_class::DEGtoRAD(double deg) {

	return(deg * PI/180.0);
}

double mathops_class::HMStoDEG(int hour, int min, double sec) {

	double totalHours;
	double degrees;

	totalHours = (double)hour + ( (double)min/60.0) + (sec/3600.0);
	
	totalHours = (totalHours >= 12.0) ? totalHours-12.0 : totalHours;

	degrees = 360.0*(totalHours/24.0);

	return(degrees);

}

double mathops_class::dot(vect_t vec1, vect_t vec2) {

	return (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z + vec2.z);

}

vect_t mathops_class::cross(vect_t vec1, vect_t vec2) {

	vect_t ret;

	ret.x = (vec1.y * vec2.z) - (vec2.y * vec1.z);
	ret.y = (vec1.z * vec2.x) - (vec2.z * vec1.x);
	ret.z = (vec1.x * vec2.y) - (vec2.x * vec1.y);

	return ret;
}

vect_t mathops_class::range(vect_t observer, vect_t target) {

	vect_t range;

	range.x = target.x - observer.x;
	range.y = target.y - observer.y;
	range.z = target.z - observer.z;

	return(range);
}

