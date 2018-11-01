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

void OutputInterfaceWindows::printToUser(string data){
	cout << "\nSystem Info: " << data << endl;
}
void OutputInterfaceWindows::printAd(string ad){
	cout << ad << endl;
}
