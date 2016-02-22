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

#endif