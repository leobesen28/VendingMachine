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
The abstract class OutputInterface is a base class which can be inherited by different systems outputs
*/
class OutputInterface{
	public:
		virtual void printToUser(string, float, short int, char) = 0;
		virtual void printAd(string) = 0;
};
/*
OutputInterfaceWindows class implements a Windows system output. 
All the output information is displayed in a windows prompt
*/
class OutputInterfaceWindows : public OutputInterface {
	public:
		void printToUser(string, float, short int, char);
		void printAd(string ad);
};
/*
OutputInterfaceARM class implements a ARM system output. 
All the output information will be implemented in an output peripheral of the STM32F429 board 
*/
class OutputInterfaceARM : public OutputInterface {
/*	public:
		void printToUser(string data);
		void printAd(string ad);
*/
};
