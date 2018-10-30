/*
-----------------------------------------------------
|		FEDERAL UNIVERSOTY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
----------------------------------------------------- 

*/

#include "AdControl.h"


AdControl::AdControl(char system){
	this->system = system;
}

//Transfer the ads located in NewAds to DisplayAds 
void AdControl::AddNewAds(void){
	Fila<Ad> aux;
	
	if(system == 0x01){
		OutputPtr = new OutputInterfaceWindows;
		InputPtr = new InputInterfaceWindows;
	}else{
		//OutputPtr = new OutputInterfaceARM;
		//InputPtr = new InputInterfaceARM;
	}
	
	if(NewAds.getHead() == 0){
		OutputPtr->printToUser("Nenhum anuncio");
	}else{
		while(NewAds.getHead() != 0){
			DisplayAds.insertAfterLast(NewAds.removeFirst());
		}
	}
	
	delete InputPtr;
	delete OutputPtr;
} 
//Display an Ad
void AdControl::SendAdToDisplay(void){
	
	if(system == 0x01){
	   	OutputPtr = new OutputInterfaceWindows;
		InputPtr = new InputInterfaceWindows;
	}else{
		//OutputPtr = new OutputInterfaceARM;
		//InputPtr = new InputInterfaceARM;
	}
	
	if(DisplayAds.getHead() == 0){
		OutputPtr->printToUser("List of advertisement is empty");
	}else{
		NowInDisplay = DisplayAds.removeFirst();
		OutputPtr->printAd(NowInDisplay.getAd());
	}
	delete InputPtr;
	delete OutputPtr;
	
}
//Return the Ad from the display to the end of the list
void AdControl::GetAdFromDisplay(void){
	DisplayAds.insertAfterLast(NowInDisplay);
} 
//Receive new ad from user
void AdControl::ReceiveNewAd(void){
	
	if(system == 0x01){
		OutputPtr = new OutputInterfaceWindows;
		InputPtr = new InputInterfaceWindows;
	}else{
		//OutputPtr = new OutputInterfaceARM;
		//InputPtr = new InputInterfaceARM;
	}
	
	OutputPtr->printToUser("Write below the new Advertisement");
	NewAds.insertAfterLast(InputPtr->inputAd());
	delete InputPtr;
	delete OutputPtr;
} 