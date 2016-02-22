#include "sidereal.h"
#include <math.h>

double sidereal_class::siderealToRadians(double sec) {

	double fractDaySeconds;
	double fractSecs;
	double seconds;
	double radians;
	mytime_t t;

	seconds = (sec < 0) ? sec * (-1) : sec;
	fractSecs =  (seconds/86400.0) - (int)(seconds/86400.0);
	fractDaySeconds = 86400.0 - (fractSecs * 86400.0);

	t.hour = (int)(fractDaySeconds / 3600.0);
	t.minute = (int)(returnFraction(fractDaySeconds / 3600.0) * 60.0);
	t.second = returnFraction((fractDaySeconds / 3600.0) * 60.0) * 60.0;

	radians=DEGtoRAD(HMStoDEG(t.hour,t.minute,t.second));

	return(radians);
}

double sidereal_class::calculateGST(mytime_t t){

	double thetaGMSTseconds;
	double thetaGST;
	double deltaT;		// fraction of day since midnight
	double thetaGMST;
	double GSTdelta;

	deltaT = (((double)t.hour*3600.0) + ((double)t.minute*60.0) + t.second);
	thetaGMSTseconds = calculateGMST(t.year, t.month, t.day);

	thetaGMST = siderealToRadians(thetaGMSTseconds);

	GSTdelta = omega_e * deltaT;

	thetaGST = thetaGMST + GSTdelta;

	return (thetaGST);

}

double sidereal_class::calculateGMST(int year, int month, int day) {
	double currentJulian;
	double Du;
	double Tu;
	double thetaGMST;

	currentJulian = julianDate(year, month, day);

	Du = currentJulian - JD0;
	Tu = Du/36525.0;

	thetaGMST = 24110.54841 + (8640184.812866 * Tu) + (0.093104 * pow(Tu,2.0)) - (6.2e-6 * pow(Tu,3.0));

	return(thetaGMST);

}

double sidereal_class::julianDate(int year, int month, int day) {

	double doy;
	double JD;

	JD = julianYear(year);
	doy = dayOfYear(year, month, day);

	return(JD+doy);
}

double sidereal_class::julianYear(int year) {
	int tmpYear;
	int A, B;

	tmpYear = year - 1;

	A = int(tmpYear/100);

	B = 2 - A + int(A/4.0);

	return (int(365.25 * tmpYear) + int(30.6001 * 14.0) + 1720994.5 + B);

}

int sidereal_class::dayOfYear(int year, int month, int day) {

	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int i;
	int tmpDay=0;

	for(i=0;i<(month-1);i++) {
		tmpDay += days[i];
	}
	tmpDay += day;

	if (((year % 4) == 0) && (((year % 100) != 0) || ((year % 400) == 0)) && (month > 2)) 
		tmpDay += 1;

	return (tmpDay);
}