/*
-----------------------------------------------------
|		FEDERAL UNIVERSOTY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
----------------------------------------------------- 

*/

#include "ButtonState.h"

ButtonState::ButtonState(void){
	M025 = 0;
	M050 = 0;
	M100 = 0; 
	DEV = 0;
	MEET = 0;
	ETIRPS = 0;
}

ButtonState::~ButtonState(void){}
	
void ButtonState::setButtonState(bool M025, bool M050, bool M100, bool DEV, bool MEET, bool ETIRPS){
	this->M025 = M025;
	this->M050 = M050;
	this->M100 = M100; 
	this->DEV = DEV;
	this->MEET = MEET;
	this->ETIRPS = ETIRPS;
}

//parametro - numero do botão
/*
1 - M025
2 - M050
3 - M100
4 - DEV
5 - MEET
6 - ETIRPS
*/
bool ButtonState::getButtonState(char numeroBotao){
	switch(numeroBotao){
		case 1:
			return M025;
			break;
		case 2:
			return M050;
			break;
		case 3:
			return M100;
			break;
		case 4:
			return DEV;
			break;
		case 5:
			return MEET;
			break;
		case 6:
			return ETIRPS;
			break;
		default:
			return 0;
			break;
	}
}




