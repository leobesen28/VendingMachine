/*

-----------------------------------------------------
|		FEDERAL UNIVERSITY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AUR�LIO BESEN					|
|			JO�O BATISTA CORDEIRO NETO				|
----------------------------------------------------- 

*/

#include "ClockCalendar.cpp"

//Log of the vending machine sells

class Logs : public ClockCalendar{
	bool meet;
	bool etirps;
	public:
		Logs();
		~Logs();
		void setLog(char);
		char getLog(void);
};