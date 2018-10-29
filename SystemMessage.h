/*

-----------------------------------------------------
|		FEDERAL UNIVERSOTY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
----------------------------------------------------- 

*/

class SystemMessage {
	  string   T000, //Credit 0.00
			   T025, //Credit 0.25
			   T050, //Credit 0.50
			   T075, //Credit 0.75
			   T100, //Credit 1.00
			   T125, //Credit 1.25
			   T150, //Credit 1.50
			   D000, //Return 0.00
			   D025, //Return 0.25
			   D050, //Return 0.50
			   D075, //Return 0.75
			   D100, //Return 1.00
			   D125, //Return 1.25
			   D150, //Return 1.50
			   S_MEET, //Reliase MEET
			   S_ETIRPS, //Reliase ETIRPS
			   NEC025, // Not enough credit
			   NEC050, // Not enough credit
			   NEC075, // Not enough credit
			   NEC100, // Not enough credit
			   NEC125, // Not enough credit
			   NEC150; // Not enough credit
	public:
		   SystemMessage(void);	
		   ~SystemMessage(void){};
		   string getSystemMessage(char index);
};