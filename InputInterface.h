/*
-----------------------------------------------------
|		FEDERAL UNIVERSOTY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
----------------------------------------------------- 

*/

#include "ButtonState.cpp"

class InputInterface : public ButtonState {
	public:
		virtual void input(void) = 0;
};

class InputInterfaceWindows : public InputInterface{
	public:
		void input(void);
};

class InputInterfaceARM : public InputInterface{
	public:
		void input(void);
};


/*
void menu(void){ //implementar na interface de saida
	
	cout << "----- MENU ----- " << endl;
	cout << "   1 - M025" << endl;
	cout << "   2 - M050" << endl;
	cout << "   3 - M100" << endl;
	cout << "   4 - DEV" << endl;
	cout << "   5 - MEET" << endl;
	cout << "   6 - ETIRPS" << endl;
}
*/
