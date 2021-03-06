/*

-----------------------------------------------------
|		FEDERAL UNIVERSITY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AUR�LIO BESEN					|
|			JO�O BATISTA CORDEIRO NETO				|
----------------------------------------------------- 

*/


template <class T>
class Fila {

  	  Node<T>* head;
  
	public:
		
  	  Fila(void);
  	  ~Fila(void);
  	  void insertAfterLast(T dat);
  	  T readFirst(void);
  	  T removeFirst(void);
  	  Node<T>* getHead(void);
};
