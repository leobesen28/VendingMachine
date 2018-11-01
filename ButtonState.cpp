/*
-----------------------------------------------------
|		FEDERAL UNIVERSOTY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AUR�LIO BESEN					|
----------------------------------------------------- 

*/

#include "ButtonState.h"

ButtonState::ButtonState(void){
	m025 = 0;
	m050 = 0;
	m100 = 0; 
	dev = 0;
	meet = 0;
	etirps = 0;
}

ButtonState::~ButtonState(void){}

/*
params
	button : 	BUTTON_M025 
				BUTTON_M050 	 
				BUTTON_M100 	
				BUTTON_DEV  	 
				BUTTON_MEET 	
				BUTTON_ETIRPS 
	
	state : 	true or false
*/


	
void ButtonState::setButtonState(char button, bool state){
	resetButtonState(0x01, 0x00);
	switch(button){
		case 0x01:
			this->m025 = state;
			break;
		case 0x02:
			this->m050 = state;
			break;
		case 0x03:
			this->m100 = state;
			break;
		case 0x04:
			this->dev = state;
			break;
		case 0x05:
			this->meet = state;
			break;
		case 0x06:
			this->etirps = state;
			break;
		default:
			//criar enum de status de opera��es STATUS_OK, STATUS_ERRO
			break;
	}	
}

/*
params
	button : 	BUTTON_M025 
				BUTTON_M050 	 
				BUTTON_M100 	
				BUTTON_DEV  	 
				BUTTON_MEET 	
				BUTTON_ETIRPS 
*/

bool ButtonState::getButtonState(char button){
	switch(button){
		case 0x01:
			return m025;
			break;
		case 0x02:
			return m050;
			break;
		case 0x03:
			return m100;
			break;
		case 0x04:
			return dev;
			break;
		case 0x05:
			return meet;
			break;
		case 0x06:
			return etirps;
			break;
		default:
			return 0;
			break;
	}
}
/*
To clear all the buttons state: allButtons = 1, buttonNumber = don't care
To clear just one button: allButtons = 0, button = 	BUTTON_M025 
													BUTTON_M050 	 
													BUTTON_M100 	
													BUTTON_DEV  	 
													BUTTON_MEET 	
													BUTTON_ETIRPS 
*/
void ButtonState::resetButtonState(char allButtons, char button){
	if(allButtons == 0x01){
		m025 = 0;
		m050 = 0;
		m100 = 0; 
		dev = 0;
		meet = 0;
		etirps = 0;
	}else{
		switch(button){
			case 0x01:
				this->m025 = 0;
				break;
			case 0x02:
				this->m050 = 0;
				break;
			case 0x03:
				this->m100 = 0;
				break;
			case 0x04:
				this->dev = 0;
				break;
			case 0x05:
				this->meet = 0;
				break;
			case 0x06:
				this->etirps = 0;
				break;
			default:
				//criar enum de status de opera��es STATUS_OK, STATUS_ERRO
				break;
			}
	}
}




