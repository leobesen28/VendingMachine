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

#include "InputInterface.h"

short int InputInterfaceWindows::inputButton(void){
	
	short int aux = 0;
	bool x = true;
	
	//System only accepts number between 1 and 6.
	//Anyother number or letter will be rejected and requested a new one

	while (x)
    {
    	string line;
        if (!getline(cin, line)) {
            cerr << "input failed" << endl;
        }
		else{
        	istringstream line_stream(line);
        	char extra;
        	if (line_stream >> aux && !(line_stream >> extra))
        		if((aux >= 0) && (aux <= 10))
            		x = false;
		}
    }
    
	return aux;
}

//Receive ads
string InputInterfaceWindows::inputAd(void){
	string c;
	getline(cin, c);
	return c;
}

//void InputInterfaceARM::inputButton(void){} //implementar 
//string InputInterfaceARM::inputAd(void){}