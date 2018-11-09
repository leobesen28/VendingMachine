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

#include "OutputInterface.h"
/*
Member function printToUser:
sel:
	0x00 - print data
	0x01 - print cash
	0x02 - print stock
*/

void OutputInterfaceWindows::printToUser(string data, float cash, int stock, char sel){
	
	switch(sel){
		case 0x00:
			cout << "\nSystem Info: " << data << endl;
			break;
		case 0x01:
			cout << "\nTotal: " << cash << endl;
			break;
		case 0x02:
			cout << "\nTotal: " << stock << endl;
			break;
		default:
			break;
	}
	
}
void OutputInterfaceWindows::printAd(string ad){
	cout << ad << endl;
}
