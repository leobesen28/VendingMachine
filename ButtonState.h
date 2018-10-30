/*
-----------------------------------------------------
|		FEDERAL UNIVERSOTY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
----------------------------------------------------- 

*/

class ButtonState{
		bool M025, M050, M100; //moedas
		bool DEV, MEET, ETIRPS;
	public:
		ButtonState(void);
		~ButtonState(void);
		void setButtonState(bool, bool, bool, bool, bool, bool);
		bool getButtonState(char);
};