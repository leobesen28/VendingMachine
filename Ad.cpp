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

Ad::Ad(void){
	advertise = "EMPTY";
}
Ad::Ad(string advertise){
	this->advertise = advertise;
}
Ad::~Ad(void){
	//cout << "Destrutor cliente..." << endl;
}
string Ad::getAd(void){
	return advertise;
}
void Ad::setAd(string advertise){
	this->advertise = advertise;
}
ostream& operator<< (ostream& c, Ad v){
	c << v.advertise;
	return c;
}