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

#include "ButtonState.cpp"

class InputInterface : public ButtonState {
	public:
		virtual void inputButton(void) = 0;
		virtual string inputAd(void) = 0;
};

class InputInterfaceWindows : public InputInterface{
	public:
		void inputButton(void);
		string inputAd(void);
};

class InputInterfaceARM : public InputInterface{
/*
	public:
		void inputButton(void);
		string inputAd(void);
*/		
};

