#include <stdio.h>
#include "mathops.h"
#include "coords.h"
#include "sidereal.h"
#include <time.h>

using namespace std;

int main(void) {

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	double test;
	double srtNow;
	double GST;
	int day;
	mytime_t tnow;
	vect_t eci;
	latlonalt_t myposition;

	mathops_class mathops;
	coords_class coords;
	sidereal_class sidereal;

	printf("Orbital Coordinate System\n");

	printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	test = sidereal.julianDate(1995,10,1);
	printf("10-1-1995 - %lf\n",test);

	srtNow = sidereal.julianDate();
	printf("SRT Now - %lf\n",srtNow);

	tnow.hour = 9;
	tnow.minute = 0;
	tnow.second = 0;
	tnow.year = 1995;
	tnow.month = 10;
	tnow.day= 1;
	GST = sidereal.calculateGST(tnow);

	printf("Greenwich Sidereal Time - %lf (%lf)\n",GST,mathops.RADtoDEG(GST));

	myposition.lat = 40;
	myposition.lon = -75;
	myposition.alt = 0;

	eci = coords.latlon2eci(myposition,mathops.RADtoDEG(GST));
	cout << "X " << eci.x << ", Y " << eci.y << ", Z " << eci.z << endl;

	return 0;
}