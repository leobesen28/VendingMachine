#include <ctime>

class ClockCalendar {
	time_t t;
	tm TM;
	short int hr, min, sec, is_pm;
	short int mo, day, yr;
public:
	ClockCalendar(void);
	void readClock(short int* clock);
	void readCalendar(short int* date);
};




