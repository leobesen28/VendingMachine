/*
-----------------------------------------------------
|		FEDERAL UNIVERSOTY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
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
};
