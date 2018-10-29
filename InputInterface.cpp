/*
-----------------------------------------------------
|		FEDERAL UNIVERSOTY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
----------------------------------------------------- 

*/

#include "InputInterface.h"

void InputInterfaceWindows::input(void){
	
	short int aux = 0;
	bool x = true;
	while (x)
    {
        cout << "Please enter the menu option number: " << flush; //Implementar na interface de saida
        string line;
        if (!getline(cin, line)) {
            cerr << "input failed" << endl;
        }
		else{
        	istringstream line_stream(line);
        	char extra;
        	if (line_stream >> aux && !(line_stream >> extra))
        		if((aux >= 1) && (aux <= 6))
            		x = false;
		}
    }
		switch(aux){
			case 1:
				setButtonState(1, 0, 0, 0, 0, 0);
				break;
			case 2:
				setButtonState(0, 1, 0, 0, 0, 0);
				break;
			case 3:
				setButtonState(0, 0, 1, 0, 0, 0);
				break;
			case 4:
				setButtonState(0, 0, 0, 1, 0, 0);
				break;
			case 5:
				setButtonState(0, 0, 0, 0, 1, 0);
				break;
			case 6:
				setButtonState(0, 0, 0, 0, 0, 1);
				break;
			default:
				setButtonState(0, 0, 0, 0, 0, 0);
				break;
		}
} 

void InputInterfaceARM::input(void){} //implementar 
