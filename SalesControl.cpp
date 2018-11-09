
#include "SalesControl.h"

//Constructor
SalesControl::SalesControl(void){
	cash = 0.0;
	Q_MEET = 2;
	Q_ETIRPS = 2;
}
//Destructor
SalesControl::~SalesControl(void){
}
//set cash  member function
void SalesControl::setCash(float cash){
	this->cash = cash;	
}
//get cash member function
float SalesControl::getCash(void){
	return cash;
}
//set que quantity of products available
//select the product in 'p'
//	p = 0x00 => MEET
//	p = 0x01 => ETIRPS 
//set the quantity in 'q'  
void SalesControl::setQuantity(char p, int q){
	if(p == 0x00){
		Q_MEET = q;
	}else if(p == 0x01){
		Q_ETIRPS = q;
	}	
}
//get que quantity of products available
//select the product in 'p'
//	p = 0x00 => MEET
//	p = 0x01 => ETIRPS 
int SalesControl::getQuantity(char p){
	if(p == 0x00){
		return Q_MEET;
	}else if(p == 0x01){
		return Q_ETIRPS;
	}
	return 0;
}
