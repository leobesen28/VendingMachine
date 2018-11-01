/*

-----------------------------------------------------
|		FEDERAL UNIVERSITY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
|			JOÃO BATISTA CORDEIRO NETO				|
----------------------------------------------------- 



This class creats an advertising object, witch will be displayed in the LCD

*/


class Ad {
		string advertisement; //Advertising message
	public:
		Ad(void); //Constructor without params
		Ad(string); //Constructor to instantiate the objetct with a message
		~Ad(void); //Destructor
		string getAd(void); //Return the advertisement 
		void setAd(string); //Change the advertisement
		friend ostream& operator<<(ostream& c, Ad v);
		
};

