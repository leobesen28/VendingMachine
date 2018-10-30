/*
-----------------------------------------------------
|		FEDERAL UNIVERSOTY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
----------------------------------------------------- 

*/

/*

This class creats an advertising object, witch will be displayed in the LCD

*/
#include "Ad.h"

Ad::Ad(void){
	advertisement = "EMPTY";
}
Ad::Ad(string advertisement){
	this->advertisement = advertisement;
}
Ad::~Ad(void){
	//cout << "Destrutor cliente..." << endl;
}
string Ad::getAd(void){
	return advertisement;
}
void Ad::setAd(string advertisement){
	this->advertisement = advertisement;
}
ostream& operator<<(ostream& c, Ad v){
	c << v.advertisement;
	return c;
}

