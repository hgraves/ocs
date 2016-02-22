#include "coords.h"
#include "math.h"
#include "mytypes.h"

/*************************************************************************
/** @brief Convert lat,lon,alt to ECI
 *
 *		@param	position		position in lat,lon.alt
 *		@param	thetaGSTdeg		Greenwich Sidereal Time in degrees
 *
 *		@return	ECI location
 *
 *		@notes	none
 *
 *************************************************************************/
vect_t coords_class::latlon2eci(latlonalt_t position, double thetaGSTdeg) {

	vect_t coords;
	double R;
	double theta;

	R = (Re + position.alt) * cos(DEGtoRAD(position.lat));

	theta = DEGtoRAD(thetaGSTdeg + position.lon);

	coords.x = R * cos(theta);
	coords.y = R * sin(theta);
	coords.z = (Re + position.alt) * sin(DEGtoRAD(position.lat));

	return(coords);

} 

/*************************************************************************
/** @brief
 *		convert local sidereal time, observer position, and target range
 *		vector into the lookangle in the topocentric-horizon coordinate
 *		system (south, east, up).
 *
 *		@param	localSRT		
 *		@param	position		
 *		@param	r
 *
 *		@return	AZ/EL/Range lookangle
 *
 *		@notes	none
 *
 *************************************************************************/
azelrange_t coords_class::lookAngle(double localSRT, latlonalt_t position, vect_t r) {

	vect_t ths;
	azelrange_t lookangle;
	double phi = DEGtoRAD(position.lat);
	double theta = DEGtoRAD(localSRT);

	// rotate the ECI frame to the topocentric-horizon frame 
	ths.x =  sin(phi)*cos(theta)*r.x + sin(phi)*sin(theta)*r.y - cos(phi)*r.z;
	ths.y = -sin(theta)*r.x + cos(theta)*r.y;
	ths.z = cos(phi)*cos(theta)*r.x + cos(phi)*sin(theta)*r.y + sin(phi)*r.z;

	// calculate looks angles
	lookangle.range = sqrt(pow(ths.x,2) + pow(ths.y,2) + pow(ths.z,2));
	lookangle.azimuth = atan((-1)*ths.y/ths.x);
	lookangle.elevation = asin(ths.z/lookangle.range);

	return (lookangle);	
}