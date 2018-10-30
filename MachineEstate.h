/*
-----------------------------------------------------
|		FEDERAL UNIVERSOTY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
----------------------------------------------------- 

*/

/*
/////////////////////////////////////////////////////////////////////////////
							TABELA DE ESTADOS
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

class MachineEstate{
	char EA;
	char system; //system: 0x01 - Windows | 0x02 - ARM
	OutputInterface* OutputPtr;
	InputInterface* InputPtr;
	SystemMessage SM;
	public:
	MachineEstate(char);
	~MachineEstate(void);	
	void nextState(void);
};
