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

template <class T>
class Stack {

  Node<T>* head;

public:
  Stack();
  ~Stack();
  void insertFirst(T dat);
  T readFirst();
  T removeFirst();
  Node<T>* getHead(void);
};

