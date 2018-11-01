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

#include "Node.cpp"

template <class T>
class Fila {

  	  Node<T>* head;
  
	public:
		
  	  Fila(void);
  	  ~Fila(void);
  	  void insertAfterLast(T dat);
  	  T readFirst(void);
  	  T removeFirst(void);
  	  void listAll(void);
  	  Node<T>* getHead(void);
};
