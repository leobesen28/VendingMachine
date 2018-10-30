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

MachineEstate::MachineEstate(char system){
	EA = 0x00; //Estate 0x00
	this->system = system;
}

MachineEstate::~MachineEstate(void){}

void MachineEstate::nextState(){
		if(system == 0x01){
			OutputPtr = new OutputInterfaceWindows;
			InputPtr = new InputInterfaceWindows;
		}else{
			//OutputPtr = new OutputInterfaceARM;
			//InputPtr = new InputInterfaceARM;
		}
		
		InputPtr->inputButton();
			
		switch(EA)
		{
			//Estate S000
			case 0x00: 
				if(InputPtr->getButtonState(1)){
					EA = 0x01;
					//  Total Credit: 25
					OutputPtr->printToUser(SM.getSystemMessage(0x01));
				}else if(InputPtr->getButtonState(2)){
					EA = 0x02;
					//   Total Credit: 50 
					OutputPtr->printToUser(SM.getSystemMessage(0x02));
				}else if(InputPtr->getButtonState(3)){
					EA = 0x04;
					//  Total Credit: 100
					OutputPtr->printToUser(SM.getSystemMessage(0x04)); 
				}else if(InputPtr->getButtonState(4)){
					EA = 0x00;
					// Return 0
					OutputPtr->printToUser(SM.getSystemMessage(0x07));  
				}else if(InputPtr->getButtonState(5)){
					EA = 0x00;
					//Not enough credit
					OutputPtr->printToUser(SM.getSystemMessage(0x15)); 
				}else if(InputPtr->getButtonState(6)){
					EA = 0x00;
					//Not enough credit
					OutputPtr->printToUser(SM.getSystemMessage(0x15));
				}else{
					EA = 0x00;	
				}
				break;
			//Estate S025
			case 0x01:
				if(InputPtr->getButtonState(1)){
					EA = 0x02;
					//  Total Credit: 50
					OutputPtr->printToUser(SM.getSystemMessage(0x02));  
				}else if(InputPtr->getButtonState(2)){
					EA = 0x03;
					//  Total Credit: 75 
					OutputPtr->printToUser(SM.getSystemMessage(0x03)); 
				}else if(InputPtr->getButtonState(3)){
					EA = 0x05;
					//  Total Credit: 125 
					OutputPtr->printToUser(SM.getSystemMessage(0x05)); 
				}else if(InputPtr->getButtonState(4)){
					EA = 0x00;
					//  Return:  25  
					OutputPtr->printToUser(SM.getSystemMessage(0x08));
				}else if(InputPtr->getButtonState(5)){
					EA = 0x01;
					OutputPtr->printToUser(SM.getSystemMessage(0x14));
				}else if(InputPtr->getButtonState(6)){
					EA = 0x01;
					OutputPtr->printToUser(SM.getSystemMessage(0x14));
				}else{
					EA = 0x01;	
				}
				break;
			//Estate S050
			case 0x02:
				if(InputPtr->getButtonState(1)){
					EA = 0x03;
					//  Total Credit: 75  
					OutputPtr->printToUser(SM.getSystemMessage(0x03));
				}else if(InputPtr->getButtonState(2)){
					EA = 0x04;
					//  Total Credit: 100
					OutputPtr->printToUser(SM.getSystemMessage(0x04));  
				}else if(InputPtr->getButtonState(3)){
					EA = 0x06;
					//  Total Credit: 150 
					OutputPtr->printToUser(SM.getSystemMessage(0x06)); 
				}else if(InputPtr->getButtonState(4)){
					EA = 0x00;
					//  Return:  50  ;
					OutputPtr->printToUser(SM.getSystemMessage(0x09));
				}else if(InputPtr->getButtonState(5)){
					EA = 0x02;
					OutputPtr->printToUser(SM.getSystemMessage(0x13));
				}else if(InputPtr->getButtonState(6)){
					EA = 0x02;
					OutputPtr->printToUser(SM.getSystemMessage(0x13));
				}else{
					EA = 0x02;	
				}
				break;
			//Estate S075
			case 0x03:
				if(InputPtr->getButtonState(1)){
					EA = 0x04;
					//  Total Credit: 100
					OutputPtr->printToUser(SM.getSystemMessage(0x04));  
				}else if(InputPtr->getButtonState(2)){
					EA = 0x05;
					//  Total Credit: 125
					OutputPtr->printToUser(SM.getSystemMessage(0x05));  
				}else if(InputPtr->getButtonState(3)){
					EA = 0x06;
					//  Total Credit: 150 
					OutputPtr->printToUser(SM.getSystemMessage(0x06)); 
					//  Return:  25  
					OutputPtr->printToUser(SM.getSystemMessage(0x08));
				}else if(InputPtr->getButtonState(4)){
					EA = 0x00;
					//  Return:  75  
					OutputPtr->printToUser(SM.getSystemMessage(0x0A));
				}else if(InputPtr->getButtonState(5)){
					EA = 0x03;
					OutputPtr->printToUser(SM.getSystemMessage(0x12));
				}else if(InputPtr->getButtonState(6)){
					EA = 0x03;
					OutputPtr->printToUser(SM.getSystemMessage(0x12));
				}else{
					EA = 0x03;	
				}
				break;
			//Estate S100
			case 0x04:
				if(InputPtr->getButtonState(1)){
					EA = 0x05;
					//  Total Credit: 125  
					OutputPtr->printToUser(SM.getSystemMessage(0x05));
				}else if(InputPtr->getButtonState(2)){
					EA = 0x06;
					//  Total Credit: 150  
					OutputPtr->printToUser(SM.getSystemMessage(0x06));
				}else if(InputPtr->getButtonState(3)){
					EA = 0x06;
					//  Total Credit: 150 
					OutputPtr->printToUser(SM.getSystemMessage(0x06)); 
					//  Return:  50  
					OutputPtr->printToUser(SM.getSystemMessage(0x09));
				}else if(InputPtr->getButtonState(4)){
					EA = 0x00;
					//  Return:  100  
					OutputPtr->printToUser(SM.getSystemMessage(0x0B));
				}else if(InputPtr->getButtonState(5)){
					EA = 0x04;
					OutputPtr->printToUser(SM.getSystemMessage(0x11));
				}else if(InputPtr->getButtonState(6)){
					EA = 0x04;
					OutputPtr->printToUser(SM.getSystemMessage(0x11));
				}else{
					EA = 0x04;	
				}
				break;
			//Estate S125
			case 0x05:
				if(InputPtr->getButtonState(1)){
					EA = 0x06;
					//  Total Credit: 150
					OutputPtr->printToUser(SM.getSystemMessage(0x06));  
				}else if(InputPtr->getButtonState(2)){
					EA = 0x06;
					//  Total Credit: 150
					OutputPtr->printToUser(SM.getSystemMessage(0x06));  
					//  Return:  25  
					OutputPtr->printToUser(SM.getSystemMessage(0x08)); 
				}else if(InputPtr->getButtonState(3)){
					EA = 0x06;
					//  Total Credit: 150
					OutputPtr->printToUser(SM.getSystemMessage(0x06));   
					//  Return:  75  
					OutputPtr->printToUser(SM.getSystemMessage(0x0A)); 
				}else if(InputPtr->getButtonState(4)){
					EA = 0x00;
					//  Return:  125  
					OutputPtr->printToUser(SM.getSystemMessage(0x0C)); 
				}else if(InputPtr->getButtonState(5)){
					EA = 0x05;
					OutputPtr->printToUser(SM.getSystemMessage(0x10)); 
				}else if(InputPtr->getButtonState(6)){
					EA = 0x05;
					OutputPtr->printToUser(SM.getSystemMessage(0x10)); 
				}else{
					EA = 0x05;	
				}
				break;
			//Estate S150
			case 0x06:
				if(InputPtr->getButtonState(1)){
					EA = 0x06;
					//  Total Credit: 150 
					OutputPtr->printToUser(SM.getSystemMessage(0x06));  
					//  Return:  25  
					OutputPtr->printToUser(SM.getSystemMessage(0x08)); 
				}else if(InputPtr->getButtonState(2)){
					EA = 0x06;
					//  Total Credit: 150  
					OutputPtr->printToUser(SM.getSystemMessage(0x06)); 
					//  Return:  50  
					OutputPtr->printToUser(SM.getSystemMessage(0x09)); 
				}else if(InputPtr->getButtonState(3)){
					EA = 0x06;
					//  Total Credit: 150 
					OutputPtr->printToUser(SM.getSystemMessage(0x06));  
					//  Return:  100  
					OutputPtr->printToUser(SM.getSystemMessage(0x0B)); 
				}else if(InputPtr->getButtonState(4)){
					EA = 0x00;
					//  Return:  150  
					OutputPtr->printToUser(SM.getSystemMessage(0x0D)); 
				}else if(InputPtr->getButtonState(5)){
					EA = 0x00;
					//  Reliased:  MEET  
					OutputPtr->printToUser(SM.getSystemMessage(0x0E)); 
				}else if(InputPtr->getButtonState(6)){
					EA = 0x00;
					//  Reliased:  ETIRPS  
					OutputPtr->printToUser(SM.getSystemMessage(0x0F)); 
				}else{
					EA = 0x06;	
				}
				break;
			default:
				break;
		}
		delete OutputPtr;
		delete InputPtr;
}
