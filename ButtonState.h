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
ButtonState class keeps the state of the buttons. Each of them if represented by
a boolean member variable of the class. 
Member functions give acess to get and set the buttons state. 

*/


/*
 ------BUTUONS DEFINES-------
*/	
#define	 BUTTON_M025 	0x01
#define	 BUTTON_M050 	0x02 
#define	 BUTTON_M100 	0x03
#define	 BUTTON_DEV  	0x04 
#define	 BUTTON_MEET 	0x05
#define	 BUTTON_ETIRPS 	0x06
#define  BUTTON_STOCK	0x07
#define  BUTTON_CASH	0x08
/*
 ----------------------------
*/
	 
class ButtonState{
		bool m025, m050, m100; //moedas
		bool dev, meet, etirps;
		bool stock, cash;
	public:
		ButtonState(void);
		~ButtonState(void);
		void setButtonState(char, bool);
		bool getButtonState(char);
		void resetButtonState(char,char);
};