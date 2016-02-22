#ifndef COORDS_H
#define COORDS_H

#include "mytypes.h"
#include "mathops.h"

class coords_class : mathops_class {
public:
	const static double Re = 6378.135;		//radius of round earth (KM)

	vect_t latlon2eci(latlonalt_t latlon, double thetaGST);
	azelrange_t lookAngle(double localSRT, latlonalt_t position, vect_t r);

private:
};



#endif