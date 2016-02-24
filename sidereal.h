#ifndef SIDEREAL_H
#define SIDEREAL_H

#include "mytypes.h"
#include "mathops.h"

class sidereal_class : mathops_class {
public:
	const static double omega_e = 7.29211510e-5;	//earth's rotation rate (rad/sec)
	const static double JD0 = 2451545.0;			//Julian date of 2000 Jan 1, 12:00 UT1

	double julianDate(int year, int month, int day);
	double julianDate();
//	int dayOfYear(int year, int month, int day);
//	double julianYear(int year);
	double calculateGMST(int year, int month, int day);
	double calculateGST(mytime_t t);
	double siderealToRadians(double sec);

private:

};

#endif