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

/*
The abstract class InputInterface is a base class which can be inherited by different systems inputs
*/

#include "ButtonState.cpp"

class InputInterface : public ButtonState {
	public:
		virtual void inputButton(void) = 0;
		virtual string inputAd(void) = 0;
};
/*
InputInterfaceWindows class implements a Windows system input. 
It gets all the user inputs, such as the menu option or new ads.
*/
class InputInterfaceWindows : public InputInterface{
	public:
		void inputButton(void);
		string inputAd(void);
};
/*
InputInterfaceARM class implements a ARM system input. 
It gets all the user inputs, such as the menu option or new ads.
*/
class InputInterfaceARM : public InputInterface{
/*
	public:
		void inputButton(void);
		string inputAd(void);
*/		
};

