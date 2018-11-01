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

class OutputInterface{
	public:
		virtual void printToUser(string) = 0;
		virtual void printAd(string) = 0;
};

class OutputInterfaceWindows : public OutputInterface {
	public:
		void printToUser(string data);
		void printAd(string ad);
};

class OutputInterfaceARM : public OutputInterface {
/*	public:
		void printToUser(string data);
		void printAd(string ad);
*/
};
