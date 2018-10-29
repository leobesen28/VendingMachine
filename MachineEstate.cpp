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

MachineEstate::MachineEstate(void){
	EA = 0x00; //Estate 0x00
}

MachineEstate::~MachineEstate(void){}

void MachineEstate::nextState(){
		switch(EA)
		{
			//Estate S000
			case 0x00: 
				if(getButtonState(1)){
					EA = 0x01;
					//  Total acumulado: 25
					printToUser(SM.getSystemMessage(0x01));
				}else if(getButtonState(2)){
					EA = 0x02;
					//   Total acumulado: 50 
					printToUser(SM.getSystemMessage(0x02));
				}else if(getButtonState(3)){
					EA = 0x04;
					//  Total acumulado: 100
					printToUser(SM.getSystemMessage(0x04)); 
				}else if(getButtonState(4)){
					EA = 0x00;
					// Return 0
					printToUser(SM.getSystemMessage(0x07));  
				}else if(getButtonState(5)){
					EA = 0x00;
					//Not enough credit
					printToUser(SM.getSystemMessage(0x15)); 
				}else if(getButtonState(6)){
					EA = 0x00;
					//Not enough credit
					printToUser(SM.getSystemMessage(0x15));
				}else{
					EA = 0x00;	
				}
				break;
			//Estate S025
			case 0x01:
				if(getButtonState(1)){
					EA = 0x02;
					//  Total acumulado: 50
					printToUser(SM.getSystemMessage(0x02));  
				}else if(getButtonState(2)){
					EA = 0x03;
					//  Total acumulado: 75 
					printToUser(SM.getSystemMessage(0x03)); 
				}else if(getButtonState(3)){
					EA = 0x05;
					//  Total acumulado: 125 
					printToUser(SM.getSystemMessage(0x05)); 
				}else if(getButtonState(4)){
					EA = 0x00;
					//  Devolve 25  
					printToUser(SM.getSystemMessage(0x08));
				}else if(getButtonState(5)){
					EA = 0x01;
					printToUser(SM.getSystemMessage(0x14));
				}else if(getButtonState(6)){
					EA = 0x01;
					printToUser(SM.getSystemMessage(0x14));
				}else{
					EA = 0x01;	
				}
				break;
			//Estate S050
			case 0x02:
				if(getButtonState(1)){
					EA = 0x03;
					//  Total acumulado: 75  
					printToUser(SM.getSystemMessage(0x03));
				}else if(getButtonState(2)){
					EA = 0x04;
					//  Total acumulado: 100
					printToUser(SM.getSystemMessage(0x04));  
				}else if(getButtonState(3)){
					EA = 0x06;
					//  Total acumulado: 150 
					printToUser(SM.getSystemMessage(0x06)); 
				}else if(getButtonState(4)){
					EA = 0x00;
					//  Devolve 50  ;
					printToUser(SM.getSystemMessage(0x09));
				}else if(getButtonState(5)){
					EA = 0x02;
					printToUser(SM.getSystemMessage(0x13));
				}else if(getButtonState(6)){
					EA = 0x02;
					printToUser(SM.getSystemMessage(0x13));
				}else{
					EA = 0x02;	
				}
				break;
			//Estate S075
			case 0x03:
				if(getButtonState(1)){
					EA = 0x04;
					//  Total acumulado: 100
					printToUser(SM.getSystemMessage(0x04));  
				}else if(getButtonState(2)){
					EA = 0x05;
					//  Total acumulado: 125
					printToUser(SM.getSystemMessage(0x05));  
				}else if(getButtonState(3)){
					EA = 0x06;
					//  Total acumulado: 150 
					printToUser(SM.getSystemMessage(0x06)); 
					//  Devolve 25  
					printToUser(SM.getSystemMessage(0x08));
				}else if(getButtonState(4)){
					EA = 0x00;
					//  Devolve 75  
					printToUser(SM.getSystemMessage(0x0A));
				}else if(getButtonState(5)){
					EA = 0x03;
					printToUser(SM.getSystemMessage(0x12));
				}else if(getButtonState(6)){
					EA = 0x03;
					printToUser(SM.getSystemMessage(0x12));
				}else{
					EA = 0x03;	
				}
				break;
			//Estate S100
			case 0x04:
				if(getButtonState(1)){
					EA = 0x05;
					//  Total acumulado: 125  
					printToUser(SM.getSystemMessage(0x05));
				}else if(getButtonState(2)){
					EA = 0x06;
					//  Total acumulado: 150  
					printToUser(SM.getSystemMessage(0x06));
				}else if(getButtonState(3)){
					EA = 0x06;
					//  Total acumulado: 150 
					printToUser(SM.getSystemMessage(0x06)); 
					//  Devolve 50  
					printToUser(SM.getSystemMessage(0x09));
				}else if(getButtonState(4)){
					EA = 0x00;
					//  Devolve 100  
					printToUser(SM.getSystemMessage(0x0B));
				}else if(getButtonState(5)){
					EA = 0x04;
					printToUser(SM.getSystemMessage(0x11));
				}else if(getButtonState(6)){
					EA = 0x04;
					printToUser(SM.getSystemMessage(0x11));
				}else{
					EA = 0x04;	
				}
				break;
			//Estate S125
			case 0x05:
				if(getButtonState(1)){
					EA = 0x06;
					//  Total acumulado: 150
					printToUser(SM.getSystemMessage(0x06));  
				}else if(getButtonState(2)){
					EA = 0x06;
					//  Total acumulado: 150
					printToUser(SM.getSystemMessage(0x06));  
					//  Devolve 25  
					printToUser(SM.getSystemMessage(0x08)); 
				}else if(getButtonState(3)){
					EA = 0x06;
					//  Total acumulado: 150
					printToUser(SM.getSystemMessage(0x06));   
					//  Devolve 75  
					printToUser(SM.getSystemMessage(0x0A)); 
				}else if(getButtonState(4)){
					EA = 0x00;
					//  Devolve 125  
					printToUser(SM.getSystemMessage(0x0C)); 
				}else if(getButtonState(5)){
					EA = 0x05;
					printToUser(SM.getSystemMessage(0x10)); 
				}else if(getButtonState(6)){
					EA = 0x05;
					printToUser(SM.getSystemMessage(0x10)); 
				}else{
					EA = 0x05;	
				}
				break;
			//Estate S150
			case 0x06:
				if(getButtonState(1)){
					EA = 0x06;
					//  Total acumulado: 150 
					printToUser(SM.getSystemMessage(0x06));  
					//  Devolve 25  
					printToUser(SM.getSystemMessage(0x08)); 
				}else if(getButtonState(2)){
					EA = 0x06;
					//  Total acumulado: 150  
					printToUser(SM.getSystemMessage(0x06)); 
					//  Devolve 50  
					printToUser(SM.getSystemMessage(0x09)); 
				}else if(getButtonState(3)){
					EA = 0x06;
					//  Total acumulado: 150 
					printToUser(SM.getSystemMessage(0x06));  
					//  Devolve 100  
					printToUser(SM.getSystemMessage(0x0B)); 
				}else if(getButtonState(4)){
					EA = 0x00;
					//  Devolve 150  
					printToUser(SM.getSystemMessage(0x0D)); 
				}else if(getButtonState(5)){
					EA = 0x00;
					//  Liberado MEET  
					printToUser(SM.getSystemMessage(0x0E)); 
				}else if(getButtonState(6)){
					EA = 0x00;
					//  Liberado ETIRPS  
					printToUser(SM.getSystemMessage(0x0F)); 
				}else{
					EA = 0x06;	
				}
				break;
			default:
				break;
		}
}
