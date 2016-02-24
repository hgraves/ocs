#ifndef MYTYPES_H
#define MYTYPES_H

typedef struct {
	double x;
	double y;
	double z;
} vect_t;

typedef struct {
	int hour;
	int minute;
	double second;
	int year;
	int month;
	int day;
} mytime_t;

typedef struct {
	double lat;
	double lon;
	double alt;
} latlonalt_t;

typedef struct {
	double azimuth;
	double elevation;
	double range;
} azelrange_t;

// typedef struct {
// 	char[24] name;
// 	int number;
// 	char classification;
// 	int launchYear;
// 	int launchNumber;
// 	char launchPiece;
// 	int epochYear;
// 	double epochDay;
// 	double dMeanMotionDiv2;
// 	double ddMeanMotionDiv6;
// 	double bstarDrag;
// 	int tleElementNumber;
// 	double inclination;
// 	double raan;
// 	double eccentricity;
// 	double argumentOfPerigee;
// 	double meanAnomaly;
// 	double meanMotion;
// 	int epochRevolutionNumber;
// } tle_t;

#endif