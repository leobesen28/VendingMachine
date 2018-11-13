/*

-----------------------------------------------------
|		FEDERAL UNIVERSITY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
|			JOÃO BATISTA CORDEIRO NETO				|
----------------------------------------------------- 

*/

/*
cash : total cash of the sales
Q_MEET : total number of MEET available to sell
Q_ETIRPS : total number of ETIPS available to sell
*/
#include <iostream>
using namespace std;
#include "Stack.cpp"
#include "Logs.cpp"

class SalesControl {
	float cash;
	short int Q_MEET, Q_ETIRPS;
	Stack<Logs>* reg;
	Logs* log;
	public:
		SalesControl(void);
		~SalesControl(void);
		void setCash(float);
		float getCash(void);
		void setQuantity(char, short int, char);
		short int getQuantity(char);
		void listLogs(OutputInterface*);
};