/*
-----------------------------------------------------
|		FEDERAL UNIVERSOTY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
----------------------------------------------------- 

This class creats an advertising object, witch will be displayed in the LCD

*/

#include "Ad.cpp"

class Ad {
		string advertise; //Advertising message
	public:
		Ad(void); //Constructor without params
		Ad(string); //Constructor to instantiate the objetct with a message
		~Ad(void); //Destructor
		int getAd(void); //Return the advertise 
		void setAd(int); //Change the advertise
		friend ostream& operator<< (ostream& c, Ad v);
};