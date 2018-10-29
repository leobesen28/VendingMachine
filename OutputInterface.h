/*
-----------------------------------------------------
|		FEDERAL UNIVERSOTY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
----------------------------------------------------- 

*/

class OutputInterface{
	public:
		virtual void printToUser(string data) = 0;
};

class OutputInterfaceWindows : public OutputInterface {
	public:
		void printToUser(string data);
		//void menu(void);
};
