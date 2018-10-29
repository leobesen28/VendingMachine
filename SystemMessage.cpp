/*
-----------------------------------------------------
|		FEDERAL UNIVERSOTY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
----------------------------------------------------- 

*/

#include "SystemMessage.h"

SystemMessage::SystemMessage(void){
	   T000 = "Credit = R$ 0.00";
	   T025 = "Credit = R$ 0.25";
	   T050 = "Credit = R$ 0.50";
	   T075 = "Credit = R$ 0.75";
	   T100 = "Credit = R$ 1.00";
	   T125 = "Credit = R$ 1.25";
	   T150 = "Credit = R$ 1.50";
	   D000 = "Returned = R$ 0.00";
	   D025 = "Returned = R$ 0.25";
	   D050 = "Returned = R$ 0.50";
	   D075 = "Returned = R$ 0.75";
	   D100 = "Returned = R$ 1.00";
	   D125 = "Returned = R$ 1.25";
	   D150 = "Returned = R$ 1.50";
	   S_MEET = "MEET released!";
	   S_ETIRPS = "EITRPS released!";
	   NEC025 = "Not enough credit, please insert more R$ 0.25";
	   NEC050 = "Not enough credit, please insert more R$ 0.50";
	   NEC075 = "Not enough credit, please insert more R$ 0.75";
	   NEC100 = "Not enough credit, please insert more R$ 1.00";
	   NEC125 = "Not enough credit, please insert more R$ 1.25";
	   NEC150 = "Not enough credit, please insert more R$ 1.50";	
}
string SystemMessage::getSystemMessage(char index){
	switch(index){
		case 0x00:
			return T000; 
			break;
		case 0x01:
			return T025; 
			break;
		case 0x02:
			return T050; 
			break;
		case 0x03:
			return T075; 
			break;
		case 0x04:
			return T100; 
			break;
		case 0x05:
			return T125; 
			break;
		case 0x06:
			return T150; 
			break;
		case 0x07:
			return D000; 
			break;
		case 0x08:
			return D025; 
			break;
		case 0x09:
			return D050; 
			break;
		case 0x0A:
			return D075; 
			break;
		case 0x0B:
			return D100; 
			break;
		case 0x0C:
			return D125; 
			break;
		case 0x0D:
			return D150; 
			break;
		case 0x0E:
			return S_MEET; 
			break;
		case 0x0F:
			return S_ETIRPS; 
			break;
		case 0x10:
			return NEC025; 
			break;
		case 0x11:
			return NEC050; 
			break;
		case 0x12:
			return NEC075; 
			break;
		case 0x13:
			return NEC100; 
			break;
		case 0x14:
			return NEC125; 
			break;
		case 0x15:
			return NEC150; 
			break;
		default:
			return "Wrong index";
			break;		
	}
}