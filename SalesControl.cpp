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

#include "SalesControl.h"

//Constructor
SalesControl::SalesControl(void){
	cash = 0.0;
	Q_MEET = 2;
	Q_ETIRPS = 2;
	
	reg = new Stack<Logs>;
}
//Destructor
SalesControl::~SalesControl(void){
	delete reg;
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
//sell - when a product was sold, sell = 0x01  
void SalesControl::setQuantity(char p, short int q, char sell){
	if(p == 0x00){
		Q_MEET = q;
	}else if(p == 0x01){
		Q_ETIRPS = q;
	}
	if(sell == 0x01){
		log = new Logs();
		log->setLog(p);
		try{
			reg->insertFirst(*log);
		}
		catch (bad_alloc erro) {
			//do something - not implemented yet
   
 	    }
		delete log;
	}
}
//get que quantity of products available
//select the product in 'p'
//	p = 0x00 => MEET
//	p = 0x01 => ETIRPS 
short int SalesControl::getQuantity(char p){
	if(p == 0x00){
		return Q_MEET;
	}else if(p == 0x01){
		return Q_ETIRPS;
	}
	return 0;
}

void SalesControl::listLogs(OutputInterface* output){
	output->printToUser("", 0.0, 0, 0x03);
	output->printToUser("LOGS", 0.0, 0, 0x00);
	Node<Logs>* auxNode = reg->getHead();
	Logs auxLog;
	short int clk[4];
	short int date[3];
	while (auxNode != 0){
		auxLog = auxNode->getValue();
		if(auxLog.getLog() == 'M'){
			output->printToUser("", 0.0, 0, 0x03);
			output->printToUser("MEET", 0.0, 0, 0x00);
		}else{
			output->printToUser("", 0.0, 0, 0x03);
			output->printToUser("ETIRPS", 0.0, 0, 0x00);
		}
		auxLog.readCalendar(date);
		auxLog.readClock(clk);
		output->printToUser(" Date: ", 0.0, 0, 0x00);
		output->printToUser("", 0.0, date[0], 0x02);
		output->printToUser("/", 0.0, 0, 0x00);
		output->printToUser("", 0.0, date[1], 0x02);
		output->printToUser("/", 0.0, 0, 0x00);
		output->printToUser("", 0.0, date[2] + 1900, 0x02);
		output->printToUser(" Hour: ", 0.0, 0, 0x00);
		output->printToUser("", 0.0, clk[0], 0x02);
		output->printToUser(":", 0.0, 0, 0x00);
		output->printToUser("", 0.0, clk[1], 0x02);
		output->printToUser(":", 0.0, 0, 0x00);
		output->printToUser("", 0.0, clk[2], 0x02);
		auxNode = auxNode->getNextNode();
    }
    output->printToUser("", 0.0, 0, 0x03);
}

