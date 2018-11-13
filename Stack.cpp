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

#include "Stack.h"

template <class T>
Stack<T>::Stack() {
   head = 0;
}

template <class T>
Stack<T>::~Stack() {
  Node<T>* cursor = head;
  while(head) {
    cursor = cursor->getNextNode();
    delete head;
    head = cursor;
  }
  head = 0; 
}

template <class T>
void Stack<T>::insertFirst(T dat) {
  head = new Node<T>(dat, this->head);
}

template <class T>
T Stack<T>::readFirst() {
   return head->getValue(); 
}

template <class T>
T Stack<T>::removeFirst() {
  T retval = 0;
  if (head != 0){
     retval = head->getValue();
     Node<T>* oldHead = head;
     head = head->getNextNode();
     delete oldHead;
  }
  return retval;
}

template <class T>
Node<T>* Stack<T>::getHead(void){
	return head;
}




