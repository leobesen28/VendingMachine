
/*
cash : total cash of the sales
Q_MEET : total number of MEET available to sell
Q_ETIRPS : total number of ETIPS available to sell
*/

class SalesControl {
	float cash;
	int Q_MEET, Q_ETIRPS;
	
	public:
		SalesControl(void);
		~SalesControl(void);
		void setCash(float);
		float getCash(void);
		void setQuantity(char, int);
		int getQuantity(char);
};