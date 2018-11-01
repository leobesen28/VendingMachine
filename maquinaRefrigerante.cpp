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

#include "main.h"


int main(int argc, char *argv[])
{

	MachineEstate MaquinaDeRefri;
	AdControl ad1;
	
	ad1.receiveNewAd();
	ad1.receiveNewAd();
	ad1.receiveNewAd();
	ad1.addNewAds();
	cout << endl;
	while(1){
			
			cout << "----- MENU ----- " << endl;
			cout << "   1 - M025" << endl;
			cout << "   2 - M050" << endl;
			cout << "   3 - M100" << endl;
			cout << "   4 - DEV" << endl;
			cout << "   5 - MEET" << endl;
			cout << "   6 - ETIRPS" << endl;
			
			MaquinaDeRefri.nextState();
			cout << endl;
			cout << "----- Advertisement -----" << endl;
			ad1.sendAdToDisplay();
			cout << endl;
			ad1.getAdFromDisplay();
	}
	return 0;
}