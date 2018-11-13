
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
	0xXX - new line
*/

void OutputInterfaceWindows::printToUser(string data, float cash, short int stock, char sel){
	

	switch(sel){
		case 0x00:
			cout << data;
			break;
		case 0x01:
			cout << cash;
			break;
		case 0x02:
			cout << stock;
			break;
		default:
			cout << endl;
			break;
	}

}
void OutputInterfaceWindows::printAd(string ad){
	cout << ad << endl;
}
