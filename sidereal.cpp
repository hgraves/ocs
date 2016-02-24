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

	int doy;
	double julianYear;
	int tmpYear;
	int A, B;
	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int i;
	int tmpDay=0;

	/* calculate julian year */
	tmpYear = year - 1;
	A = int(tmpYear/100);
	B = 2 - A + int(A/4.0);
	julianYear = int(365.25 * tmpYear) + int(30.6001 * 14.0) + 1720994.5 + B;

	/* calculate julian year */
	for(i=0;i<(month-1);i++) {
		tmpDay += days[i];
	}
	tmpDay += day;

	if (((year % 4) == 0) && (((year % 100) != 0) || ((year % 400) == 0)) && (month > 2)) 
		tmpDay += 1;

	doy = tmpDay;

	return(julianYear + (double)doy);
}

double sidereal_class::julianDate() {

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int doy;
	double julianYear;
	int tmpYear;
	int A, B;
	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int i;
	int tmpDay=0;
	int year=tm.tm_year + 1900; 
	int month=tm.tm_mon + 1;
	int day=tm.tm_mday;

	/* calculate julian year */
	tmpYear = year - 1;
	A = int(tmpYear/100);
	B = 2 - A + int(A/4.0);
	julianYear = int(365.25 * tmpYear) + int(30.6001 * 14.0) + 1720994.5 + B;

	/* calculate julian year */
	for(i=0;i<(month-1);i++) {
		tmpDay += days[i];
	}
	tmpDay += day;

	if (((year % 4) == 0) && (((year % 100) != 0) || ((year % 400) == 0)) && (month > 2)) 
		tmpDay += 1;

	doy = tmpDay;

	return(julianYear + (double)doy);
}