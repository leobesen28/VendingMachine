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
/////////////////////////////////////////////////////////////////////////////
							TABLE OF STATES
EA		NADA	M025		M050		M100		DEV			MEET	ETIRPS
0x00	0x00	0x01		0x02		0x04		0x00		0x00	0x00
0x01	0x01	0x02		0x03		0x05		0x00,D025	0x01	0x01
0x02	0x02	0x03		0x04		0x06		0x00,D050	0x02	0x02
0x03	0x03	0x04		0x05		0x06, D025	0x00,D075	0x03	0x03
0x04	0x04	0x05		0x06		0x06, D050	0x00,D100	0x04	0x04
0x05	0x05	0x06		0x06,D025	0x06, D075	0x00,D125	0x05	0x05
0x06	0x06	0x06,D025	0x06,D050	0x06, D100	0x00,D150	0x00	0x00
//////////////////////////////////////////////////////////////////////////////
*/

/*
MachineState class is the FSM of the Vending Machine. 
Member Variables:
	state : keeps the current state of the FSM
	outputPtr : pointer to an output - polymorphism technique
	inputPtr : pointer to an inputPtr - polymorphism technique
	sm : an object with the system info messages
Member Function:
	MachineState : Constructor
	~MachineState : Destructor
	nextState : move to next state
*/

#include "SalesControl.cpp"
#include "ButtonState.cpp"

class MachineState : public SalesControl, public ButtonState {
		char state;
		OutputInterface* outputPtr;
		InputInterface* inputPtr;
	public:
		MachineState(void);
		~MachineState(void);	
		void nextState(void);
};
