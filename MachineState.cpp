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

#include "MachineState.h"

MachineState::MachineState(){
	

	#ifdef SYSTEM_WINDOWS
		outputPtr = new OutputInterfaceWindows;
		inputPtr = new InputInterfaceWindows;
	#endif
	#ifdef SYSTEM_STM32
		//outputPtr = new OutputInterfacstateRM;
		//inputPtr = new InputInterfacstateRM;
	#endif
	
	state = 0x00; //State 0x00	
}

MachineState::~MachineState(void){
	delete outputPtr;
	delete inputPtr;
}

void MachineState::nextState(){
		
		//Get the input pressed/informed button
 	   //Switch between the button/option choosed
		switch(inputPtr->inputButton()){
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
			case 7:
				setButtonState(BUTTON_STOCK, 1);
				break;
			case 8:
				setButtonState(BUTTON_CASH, 1);
				break;
			default:
				break;
		} 
			
		switch(state)
		{
			//Estate S000
			case 0x00: 
				if(getButtonState(0x01)){
					state = 0x01;
					//  Total Credit: 25
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 0.25", 0.0, 0, 0x00);
				}else if(getButtonState(0x02)){
					state = 0x02;
					//   Total Credit: 50 
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 0.50", 0.0, 0, 0x00);
				}else if(getButtonState(0x03)){
					state = 0x04;
					//  Total Credit: 100
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 1.00", 0.0, 0, 0x00); 
				}else if(getButtonState(0x04)){
					state = 0x00;
					// Return 0
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Returned = R$ 0.00", 0.0, 0, 0x00);  
				}else if(getButtonState(0x05)){
					state = 0x00;
					//Not enough credit
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Not enough credit, please insert more R$ 1.50", 0.0, 0, 0x00); 
				}else if(getButtonState(0x06)){
					state = 0x00;
					//Not enough credit
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Not enough credit, please insert more R$ 1.50", 0.0, 0, 0x00);
				}else if(getButtonState(0x07)){
					state = 0x00;
					//STOCK
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Available MEET ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", 0.0, getQuantity(0x00), 0x02);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Available ETIRPS ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", 0.0, getQuantity(0x01), 0x02);
					
					addInStock();
				}else if(getButtonState(0x08)){
					state = 0x00;
					//CASH
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("CASH ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", getCash(), 0, 0x01);
				}else{
					state = 0x00;	
				}
				break;
			//Estate S025
			case 0x01:
				if(getButtonState(0x01)){
					state = 0x02;
					//  Total Credit: 50
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 0.50", 0.0, 0, 0x00);  
				}else if(getButtonState(0x02)){
					state = 0x03;
					//  Total Credit: 75 
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 0.75", 0.0, 0, 0x00); 
				}else if(getButtonState(0x03)){
					state = 0x05;
					//  Total Credit: 125 
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 1.25", 0.0, 0, 0x00); 
				}else if(getButtonState(0x04)){
					state = 0x00;
					//  Return:  25  
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Returned = R$ 0.25", 0.0, 0, 0x00);
				}else if(getButtonState(0x05)){
					state = 0x01;
					//Not enough credit
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Not enough credit, please insert more R$ 1.25", 0.0, 0, 0x00);
				}else if(getButtonState(0x06)){
					state = 0x01;
					//Not enough credit
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Not enough credit, please insert more R$ 1.25", 0.0, 0, 0x00);
				}else if(getButtonState(0x07)){
					state = 0x01;
					//STOCK
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Available MEET ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", 0.0, getQuantity(0x00), 0x02);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Available ETIRPS ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", 0.0, getQuantity(0x01), 0x02);
					
					addInStock();
				}else if(getButtonState(0x08)){
					state = 0x01;
					//CASH
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("CASH ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", getCash(), 0, 0x01);
				}else{
					state = 0x01;	
				}
				break;
			//Estate S050
			case 0x02:
				if(getButtonState(0x01)){
					state = 0x03;
					//  Total Credit: 75  
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 0.75", 0.0, 0, 0x00);
				}else if(getButtonState(0x02)){
					state = 0x04;
					//  Total Credit: 100
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 1.00", 0.0, 0, 0x00);  
				}else if(getButtonState(0x03)){
					state = 0x06;
					//  Total Credit: 150 
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 1.50", 0.0, 0, 0x00); 
				}else if(getButtonState(0x04)){
					state = 0x00;
					//  Return:  50  ;
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Returned = R$ 0.50", 0.0, 0, 0x00);
				}else if(getButtonState(0x05)){
					state = 0x02;
					//Not enough credit
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Not enough credit, please insert more R$ 1.00", 0.0, 0, 0x00);
				}else if(getButtonState(0x06)){
					state = 0x02;
					//Not enough credit
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Not enough credit, please insert more R$ 1.00", 0.0, 0, 0x00);
				}else if(getButtonState(0x07)){
					state = 0x02;
					//STOCK
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Available MEET ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", 0.0, getQuantity(0x00), 0x02);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Available ETIRPS ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", 0.0, getQuantity(0x01), 0x02);
					
					addInStock();
				}else if(getButtonState(0x08)){
					state = 0x02;
					//CASH
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("CASH ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", getCash(), 0, 0x01);
				}else{
					state = 0x02;	
				}
				break;
			//Estate S075
			case 0x03:
				if(getButtonState(0x01)){
					state = 0x04;
					//  Total Credit: 100
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 1.00", 0.0, 0, 0x00);  
				}else if(getButtonState(0x02)){
					state = 0x05;
					//  Total Credit: 125
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 1.25", 0.0, 0, 0x00);  
				}else if(getButtonState(0x03)){
					state = 0x06;
					//  Total Credit: 150 
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 1.50", 0.0, 0, 0x00); 
					//  Return:  25  
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Returned = R$ 0.25", 0.0, 0, 0x00);
				}else if(getButtonState(0x04)){
					state = 0x00;
					//  Return:  75  
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Returned = R$ 0.75", 0.0, 0, 0x00);
				}else if(getButtonState(0x05)){
					state = 0x03;
					//Not enough credit
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Not enough credit, please insert more R$ 0.75", 0.0, 0, 0x00);
				}else if(getButtonState(0x06)){
					state = 0x03;
					//Not enough credit
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Not enough credit, please insert more R$ 0.75", 0.0, 0, 0x00);
				}else if(getButtonState(0x07)){
					state = 0x03;
					//STOCK
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Available MEET ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", 0.0, getQuantity(0x00), 0x02);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Available ETIRPS ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", 0.0, getQuantity(0x01), 0x02);
					
					addInStock();
				}else if(getButtonState(0x08)){
					state = 0x03;
					//CASH
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("CASH ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", getCash(), 0, 0x01);
				}else{
					state = 0x03;	
				}
				break;
			//Estate S100
			case 0x04:
				if(getButtonState(0x01)){
					state = 0x05;
					//  Total Credit: 125  
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 1.25", 0.0, 0, 0x00);
				}else if(getButtonState(0x02)){
					state = 0x06;
					//  Total Credit: 150  
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 1.50", 0.0, 0, 0x00);
				}else if(getButtonState(0x03)){
					state = 0x06;
					//  Total Credit: 150 
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 1.50", 0.0, 0, 0x00); 
					//  Return:  50  
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Returned = R$ 0.50", 0.0, 0, 0x00);
				}else if(getButtonState(0x04)){
					state = 0x00;
					//  Return:  100  
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Returned = R$ 1.00", 0.0, 0, 0x00);
				}else if(getButtonState(0x05)){
					state = 0x04;
					//Not enough credit
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Not enough credit, please insert more R$ 0.50", 0.0, 0, 0x00);
				}else if(getButtonState(0x06)){
					state = 0x04;
					//Not enough credit
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Not enough credit, please insert more R$ 0.50", 0.0, 0, 0x00);
				}else if(getButtonState(0x07)){
					state = 0x04;
					//STOCK
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Available MEET ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", 0.0, getQuantity(0x00), 0x02);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Available ETIRPS ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", 0.0, getQuantity(0x01), 0x02);
					
					addInStock();
				}else if(getButtonState(0x08)){
					state = 0x04;
					//CASH
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("CASH ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", getCash(), 0, 0x01);
				}else{
					state = 0x04;	
				}
				break;
			//Estate S125
			case 0x05:
				if(getButtonState(0x01)){
					state = 0x06;
					//  Total Credit: 150
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 1.50", 0.0, 0, 0x00);  
				}else if(getButtonState(0x02)){
					state = 0x06;
					//  Total Credit: 150
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 1.50", 0.0, 0, 0x00);  
					//  Return:  25  
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Returned = R$ 0.25", 0.0, 0, 0x00); 
				}else if(getButtonState(0x03)){
					state = 0x06;
					//  Total Credit: 150
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 1.50", 0.0, 0, 0x00);   
					//  Return:  75  
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Returned = R$ 0.75", 0.0, 0, 0x00); 
				}else if(getButtonState(0x04)){
					state = 0x00;
					//  Return:  125  
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Returned = R$ 1.25", 0.0, 0, 0x00); 
				}else if(getButtonState(0x05)){
					state = 0x05;
					//Not enough credit
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Not enough credit, please insert more R$ 0.25", 0.0, 0, 0x00); 
				}else if(getButtonState(0x06)){
					state = 0x05;
					//Not enough credit
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Not enough credit, please insert more R$ 0.25", 0.0, 0, 0x00);
				}else if(getButtonState(0x07)){
					state = 0x05;
					//STOCK
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Available MEET ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", 0.0, getQuantity(0x00), 0x02);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Available ETIRPS ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", 0.0, getQuantity(0x01), 0x02);
					
					addInStock();
				}else if(getButtonState(0x08)){
					state = 0x05;
					//CASH
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("CASH ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", getCash(), 0, 0x01); 
				}else{
					state = 0x05;	
				}
				break;
			//Estate S150
			case 0x06:
				if(getButtonState(0x01)){
					state = 0x06;
					//  Total Credit: 150 
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 1.50", 0.0, 0, 0x00);  
					//  Return:  25  
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Returned = R$ 0.25", 0.0, 0, 0x00); 
				}else if(getButtonState(0x02)){
					state = 0x06;
					//  Total Credit: 150  
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 1.50", 0.0, 0, 0x00); 
					//  Return:  50  
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Returned = R$ 0.50", 0.0, 0, 0x00); 
				}else if(getButtonState(0x03)){
					state = 0x06;
					//  Total Credit: 150 
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Credit = R$ 1.50", 0.0, 0, 0x00);  
					//  Return:  100  
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Returned = R$ 1.00", 0.0, 0, 0x00); 
				}else if(getButtonState(0x04)){
					state = 0x00;
					//  Return:  150  
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Returned = R$ 1.50", 0.0, 0, 0x00); 
				}else if(getButtonState(0x05)){
					if(getQuantity(0x00) == 0){
						outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("STOCK OF MEET EMPTY", 0.0, 0, 0x00);
						outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("SELECT OTHER OR PRESS DEV", 0.0, 0, 0x00);
						state = 0x06;
					}else{
						state = 0x00;
						//  Reliase:  MEET  
						outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("MEET released!", 0.0, 0, 0x00);
						//Save the nem amount of cash
						setCash(getCash() + 1.50);
						//Decrement the product quantity
						setQuantity(0x00, getQuantity(0x00) - 1, 0x01);
					} 
				}else if(getButtonState(0x06)){
					if(getQuantity(0x01) == 0){
						outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("STOCK OF ETIRPS EMPTY", 0.0, 0, 0x00);
						outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("SELECT OTHER OR PRESS DEV", 0.0, 0, 0x00);
						state = 0x06;
					}else{
						state = 0x00;
						//  Reliase:  ETIRPS  
						outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("ETIRPS released!", 0.0, 0, 0x00);
						//Save the nem amount of cash
						setCash(getCash() + 1.50);
						//Decrement the product quantity
						setQuantity(0x01, getQuantity(0x01) - 1, 0x01);
					}
				}else if(getButtonState(0x07)){
					state = 0x06;
					//STOCK
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Available MEET ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", 0.0, getQuantity(0x00), 0x02);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("Available ETIRPS ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", 0.0, getQuantity(0x01), 0x02);
					
					addInStock();
				}else if(getButtonState(0x08)){
					state = 0x06;
					//CASH
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("CASH ", 0.0, 0, 0x00);
					outputPtr->printToUser("", 0.0, 0, 0x03); outputPtr->printToUser("", getCash(), 0, 0x01);
				}else{
					state = 0x06;	
				}
				break;
			default:
				break;
		}

}

void MachineState::addInStock(void){
	listLogs(outputPtr);
	
	short int aux;
	
	outputPtr->printToUser("", 0.0, 0, 0x03); 
	outputPtr->printToUser("ADD MORE TO STOCK? 1 - YES, 0 - NO", 0.0, 0, 0x00);
	outputPtr->printToUser("", 0.0, 0, 0x03);
	if(inputPtr->inputButton() == 1){
		outputPtr->printToUser("", 0.0, 0, 0x03); 
		outputPtr->printToUser("ADD MORE MEET? 1 - YES, 0 - NO", 0.0, 0, 0x00);
		outputPtr->printToUser("", 0.0, 0, 0x03);
		if(inputPtr->inputButton() == 1){
			outputPtr->printToUser("", 0.0, 0, 0x03); 
			outputPtr->printToUser("ADD MEET QUANTITY - MAX 10", 0.0, 0, 0x00);
			outputPtr->printToUser("", 0.0, 0, 0x03);
			aux = inputPtr->inputButton() + getQuantity(0x00);
			if(aux <= 10){
				setQuantity(0x00, aux, 0x00);
				outputPtr->printToUser("", 0.0, 0, 0x03); 
				outputPtr->printToUser("ADDED MEET!", 0.0, 0, 0x00);
			}else{
				outputPtr->printToUser("", 0.0, 0, 0x03); 
				outputPtr->printToUser("NOT ADDED MEET!", 0.0, 0, 0x00);
			}
		}
		outputPtr->printToUser("", 0.0, 0, 0x03); 
		outputPtr->printToUser("ADD MORE ETIRPS? 1 - YES, 0 - NO", 0.0, 0, 0x00);
		outputPtr->printToUser("", 0.0, 0, 0x03);
		if(inputPtr->inputButton() == 1){
			outputPtr->printToUser("", 0.0, 0, 0x03); 
			outputPtr->printToUser("ADD ETIRPS QUANTITY - MAX 10", 0.0, 0, 0x00);
			outputPtr->printToUser("", 0.0, 0, 0x03);
			aux = inputPtr->inputButton() + getQuantity(0x01);
			if(aux <= 10){
				setQuantity(0x01, aux, 0x00);
				outputPtr->printToUser("", 0.0, 0, 0x03); 
				outputPtr->printToUser("ADDED ETIRPS!", 0.0, 0, 0x00);
			}else{
				outputPtr->printToUser("", 0.0, 0, 0x03); 
				outputPtr->printToUser("NOT ADDED ETIRPS!", 0.0, 0, 0x00);
			}
		}
	}
}
	

