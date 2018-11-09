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

#include "Ad.cpp"
#include "Fila.cpp"

class AdControl {
		Fila<Ad> displayAds;
		Fila<Ad> newAds;
		Ad nowInDisplay;
		InputInterface* inputPtr;
		OutputInterface* outputPtr;
	public:
		AdControl(void);
		~AdControl(void);
		void addNewAds(void); //Transfer the ads located in NewAds to DisplayAds 
		void sendAdToDisplay(void); //Display an Ad
		void getAdFromDisplay(void); //Return the Ad from the display to the end of the list
		void receiveNewAd(void); //Receive new ad from user
};



