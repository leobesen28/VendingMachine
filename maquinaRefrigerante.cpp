/*
-----------------------------------------------------
|		FEDERAL UNIVERSOTY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
----------------------------------------------------- 

*/

#include "main.h"
#include "MachineEstate.cpp"



int main(int argc, char *argv[])
{

	MachineEstate MaquinaDeRefri;
	
	while(1){
			
			cout << "----- MENU ----- " << endl;
			cout << "   1 - M025" << endl;
			cout << "   2 - M050" << endl;
			cout << "   3 - M100" << endl;
			cout << "   4 - DEV" << endl;
			cout << "   5 - MEET" << endl;
			cout << "   6 - ETIRPS" << endl;
			
			MaquinaDeRefri.input();
			MaquinaDeRefri.nextState();
	}
	return 0;
}