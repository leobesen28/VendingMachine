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

AdControl::AdControl(void){
	
	#ifdef SYSTEM_WINDOWS
		outputPtr = new OutputInterfaceWindows;
		inputPtr = new InputInterfaceWindows;
	#endif
	#ifdef SYSTEM_STM32
		//outputPtr = new OutputInterfaceARM;
		//inputPtr = new InputInterfaceARM;
	#endif	
}

AdControl::~AdControl(void){
	delete inputPtr;
	delete outputPtr;
}

//Transfer the ads located in NewAds to DisplayAds 
void AdControl::addNewAds(void){
	
	if(newAds.getHead() == 0){
		outputPtr->printToUser("No ads to display...");
	}else{
		while(newAds.getHead() != 0){
			displayAds.insertAfterLast(newAds.removeFirst());
		}
	}
} 
//Display an Ad
void AdControl::sendAdToDisplay(void){
	
	if(displayAds.getHead() == 0){
		outputPtr->printToUser("List of advertisement is empty");
	}else{
		nowInDisplay = displayAds.removeFirst();
		outputPtr->printAd(nowInDisplay.getAd());
	}	
}
//Return the Ad from the display to the end of the list
void AdControl::getAdFromDisplay(void){
	
	displayAds.insertAfterLast(nowInDisplay);
} 
//Receive new ad from user
void AdControl::receiveNewAd(void){
	
	outputPtr->printToUser("Write below the new Advertisement");
	newAds.insertAfterLast(inputPtr->inputAd());
} 