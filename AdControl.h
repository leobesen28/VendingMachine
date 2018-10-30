/*
-----------------------------------------------------
|		FEDERAL UNIVERSOTY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
----------------------------------------------------- 

*/ 

#include "Ad.cpp"


class AdControl {
		char system;
		Fila<Ad> DisplayAds;
		Fila<Ad> NewAds;
		Ad NowInDisplay;
		InputInterface* InputPtr;
		OutputInterface* OutputPtr;
	public:
		AdControl(char);
		void AddNewAds(void); //Transfer the ads located in NewAds to DisplayAds 
		void SendAdToDisplay(void); //Display an Ad
		void GetAdFromDisplay(void); //Return the Ad from the display to the end of the list
		void ReceiveNewAd(void); //Receive new ad from user
};



