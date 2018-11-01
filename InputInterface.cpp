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

void InputInterfaceWindows::inputButton(void){
	
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
				setButtonState(BUTTON_M025, 1);
				break;
			case 2:
				setButtonState(BUTTON_M050, 1);
				break;
			case 3:
				setButtonState(BUTTON_M100, 1);
				break;
			case 4:
				setButtonState(BUTTON_DEV, 1);
				break;
			case 5:
				setButtonState(BUTTON_MEET, 1);
				break;
			case 6:
				setButtonState(BUTTON_ETIRPS, 1);
				break;
			default:
				break;
		}
} 

string InputInterfaceWindows::inputAd(void){
	string c;
	getline(cin, c);
	return c;
}

void InputInterfaceARM::inputButton(void){} //implementar 
//string InputInterfaceARM::inputAd(void){}