/*
-----------------------------------------------------
|		FEDERAL UNIVERSOTY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
----------------------------------------------------- 

*/

#include "MachineEstate.h"

MachineEstate::MachineEstate(){
	
	#ifdef SYSTEM_WINDOWS
		outputPtr = new OutputInterfaceWindows;
		inputPtr = new InputInterfaceWindows;
	#endif
	#ifdef SYSTEM_STM32
		//outputPtr = new OutputInterfacstateRM;
		//inputPtr = new InputInterfacstateRM;
	#endif
	
	state = 0x00; //Estate 0x00	
}

MachineEstate::~MachineEstate(void){
	delete outputPtr;
	delete inputPtr;
}

void MachineEstate::nextState(){
		
		inputPtr->inputButton();
			
		switch(state)
		{
			//Estate S000
			case 0x00: 
				if(inputPtr->getButtonState(0x01)){
					state = 0x01;
					//  Total Credit: 25
					outputPtr->printToUser(sm.getSystemMessage(0x01));
				}else if(inputPtr->getButtonState(0x02)){
					state = 0x02;
					//   Total Credit: 50 
					outputPtr->printToUser(sm.getSystemMessage(0x02));
				}else if(inputPtr->getButtonState(0x03)){
					state = 0x04;
					//  Total Credit: 100
					outputPtr->printToUser(sm.getSystemMessage(0x04)); 
				}else if(inputPtr->getButtonState(0x04)){
					state = 0x00;
					// Return 0
					outputPtr->printToUser(sm.getSystemMessage(0x07));  
				}else if(inputPtr->getButtonState(0x05)){
					state = 0x00;
					//Not enough credit
					outputPtr->printToUser(sm.getSystemMessage(0x15)); 
				}else if(inputPtr->getButtonState(0x06)){
					state = 0x00;
					//Not enough credit
					outputPtr->printToUser(sm.getSystemMessage(0x15));
				}else{
					state = 0x00;	
				}
				break;
			//Estate S025
			case 0x01:
				if(inputPtr->getButtonState(0x01)){
					state = 0x02;
					//  Total Credit: 50
					outputPtr->printToUser(sm.getSystemMessage(0x02));  
				}else if(inputPtr->getButtonState(0x02)){
					state = 0x03;
					//  Total Credit: 75 
					outputPtr->printToUser(sm.getSystemMessage(0x03)); 
				}else if(inputPtr->getButtonState(0x03)){
					state = 0x05;
					//  Total Credit: 125 
					outputPtr->printToUser(sm.getSystemMessage(0x05)); 
				}else if(inputPtr->getButtonState(0x04)){
					state = 0x00;
					//  Return:  25  
					outputPtr->printToUser(sm.getSystemMessage(0x08));
				}else if(inputPtr->getButtonState(0x05)){
					state = 0x01;
					outputPtr->printToUser(sm.getSystemMessage(0x14));
				}else if(inputPtr->getButtonState(0x06)){
					state = 0x01;
					outputPtr->printToUser(sm.getSystemMessage(0x14));
				}else{
					state = 0x01;	
				}
				break;
			//Estate S050
			case 0x02:
				if(inputPtr->getButtonState(0x01)){
					state = 0x03;
					//  Total Credit: 75  
					outputPtr->printToUser(sm.getSystemMessage(0x03));
				}else if(inputPtr->getButtonState(0x02)){
					state = 0x04;
					//  Total Credit: 100
					outputPtr->printToUser(sm.getSystemMessage(0x04));  
				}else if(inputPtr->getButtonState(0x03)){
					state = 0x06;
					//  Total Credit: 150 
					outputPtr->printToUser(sm.getSystemMessage(0x06)); 
				}else if(inputPtr->getButtonState(0x04)){
					state = 0x00;
					//  Return:  50  ;
					outputPtr->printToUser(sm.getSystemMessage(0x09));
				}else if(inputPtr->getButtonState(0x05)){
					state = 0x02;
					outputPtr->printToUser(sm.getSystemMessage(0x13));
				}else if(inputPtr->getButtonState(0x06)){
					state = 0x02;
					outputPtr->printToUser(sm.getSystemMessage(0x13));
				}else{
					state = 0x02;	
				}
				break;
			//Estate S075
			case 0x03:
				if(inputPtr->getButtonState(0x01)){
					state = 0x04;
					//  Total Credit: 100
					outputPtr->printToUser(sm.getSystemMessage(0x04));  
				}else if(inputPtr->getButtonState(0x02)){
					state = 0x05;
					//  Total Credit: 125
					outputPtr->printToUser(sm.getSystemMessage(0x05));  
				}else if(inputPtr->getButtonState(0x03)){
					state = 0x06;
					//  Total Credit: 150 
					outputPtr->printToUser(sm.getSystemMessage(0x06)); 
					//  Return:  25  
					outputPtr->printToUser(sm.getSystemMessage(0x08));
				}else if(inputPtr->getButtonState(0x04)){
					state = 0x00;
					//  Return:  75  
					outputPtr->printToUser(sm.getSystemMessage(0x0A));
				}else if(inputPtr->getButtonState(0x05)){
					state = 0x03;
					outputPtr->printToUser(sm.getSystemMessage(0x12));
				}else if(inputPtr->getButtonState(0x06)){
					state = 0x03;
					outputPtr->printToUser(sm.getSystemMessage(0x12));
				}else{
					state = 0x03;	
				}
				break;
			//Estate S100
			case 0x04:
				if(inputPtr->getButtonState(0x01)){
					state = 0x05;
					//  Total Credit: 125  
					outputPtr->printToUser(sm.getSystemMessage(0x05));
				}else if(inputPtr->getButtonState(0x02)){
					state = 0x06;
					//  Total Credit: 150  
					outputPtr->printToUser(sm.getSystemMessage(0x06));
				}else if(inputPtr->getButtonState(0x03)){
					state = 0x06;
					//  Total Credit: 150 
					outputPtr->printToUser(sm.getSystemMessage(0x06)); 
					//  Return:  50  
					outputPtr->printToUser(sm.getSystemMessage(0x09));
				}else if(inputPtr->getButtonState(0x04)){
					state = 0x00;
					//  Return:  100  
					outputPtr->printToUser(sm.getSystemMessage(0x0B));
				}else if(inputPtr->getButtonState(0x05)){
					state = 0x04;
					outputPtr->printToUser(sm.getSystemMessage(0x11));
				}else if(inputPtr->getButtonState(0x06)){
					state = 0x04;
					outputPtr->printToUser(sm.getSystemMessage(0x11));
				}else{
					state = 0x04;	
				}
				break;
			//Estate S125
			case 0x05:
				if(inputPtr->getButtonState(0x01)){
					state = 0x06;
					//  Total Credit: 150
					outputPtr->printToUser(sm.getSystemMessage(0x06));  
				}else if(inputPtr->getButtonState(0x02)){
					state = 0x06;
					//  Total Credit: 150
					outputPtr->printToUser(sm.getSystemMessage(0x06));  
					//  Return:  25  
					outputPtr->printToUser(sm.getSystemMessage(0x08)); 
				}else if(inputPtr->getButtonState(0x03)){
					state = 0x06;
					//  Total Credit: 150
					outputPtr->printToUser(sm.getSystemMessage(0x06));   
					//  Return:  75  
					outputPtr->printToUser(sm.getSystemMessage(0x0A)); 
				}else if(inputPtr->getButtonState(0x04)){
					state = 0x00;
					//  Return:  125  
					outputPtr->printToUser(sm.getSystemMessage(0x0C)); 
				}else if(inputPtr->getButtonState(0x05)){
					state = 0x05;
					outputPtr->printToUser(sm.getSystemMessage(0x10)); 
				}else if(inputPtr->getButtonState(0x06)){
					state = 0x05;
					outputPtr->printToUser(sm.getSystemMessage(0x10)); 
				}else{
					state = 0x05;	
				}
				break;
			//Estate S150
			case 0x06:
				if(inputPtr->getButtonState(0x01)){
					state = 0x06;
					//  Total Credit: 150 
					outputPtr->printToUser(sm.getSystemMessage(0x06));  
					//  Return:  25  
					outputPtr->printToUser(sm.getSystemMessage(0x08)); 
				}else if(inputPtr->getButtonState(0x02)){
					state = 0x06;
					//  Total Credit: 150  
					outputPtr->printToUser(sm.getSystemMessage(0x06)); 
					//  Return:  50  
					outputPtr->printToUser(sm.getSystemMessage(0x09)); 
				}else if(inputPtr->getButtonState(0x03)){
					state = 0x06;
					//  Total Credit: 150 
					outputPtr->printToUser(sm.getSystemMessage(0x06));  
					//  Return:  100  
					outputPtr->printToUser(sm.getSystemMessage(0x0B)); 
				}else if(inputPtr->getButtonState(0x04)){
					state = 0x00;
					//  Return:  150  
					outputPtr->printToUser(sm.getSystemMessage(0x0D)); 
				}else if(inputPtr->getButtonState(0x05)){
					state = 0x00;
					//  Reliased:  MEET  
					outputPtr->printToUser(sm.getSystemMessage(0x0E)); 
				}else if(inputPtr->getButtonState(0x06)){
					state = 0x00;
					//  Reliased:  ETIRPS  
					outputPtr->printToUser(sm.getSystemMessage(0x0F)); 
				}else{
					state = 0x06;	
				}
				break;
			default:
				break;
		}

}
