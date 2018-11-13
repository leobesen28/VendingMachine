#include "ClockCalendar.h"

ClockCalendar::ClockCalendar(void) {
	
	time( &t );
	TM = *localtime( &t );
	hr = TM.tm_hour;
	min = TM.tm_min;
	sec = TM.tm_sec;
	is_pm = 0;
	mo = TM.tm_mon;
	day = TM.tm_mday;
	yr = TM.tm_year;
}
/*
Get time clock

*/

void ClockCalendar::readClock(short int* clock) {
	clock[0] = hr;
	clock[1] = min;
	clock[2] = sec;
	clock[3] = is_pm;
}
/*
Get date
*/

void ClockCalendar::readCalendar(short int* date) {
	date[0] = mo;
	date[1] = day;
	date[2] = yr;
}

