/*
-----------------------------------------------------
|		FEDERAL UNIVERSOTY OF SANTA CATARINA		|
|			C++ FOR EMBEDDED SYSTEMS				|
|			PROJECT: VENDING MACHINE				|
|		PROFESSOR: EDUARDO AUGUSTO BEZERRA			|
| 	 	 	 LEONARDO AURÉLIO BESEN					|
----------------------------------------------------- 

*/

#include "Fila.h"

template <class T>
Fila<T>::Fila() {
   head = 0;
}

template <class T>
Fila<T>::~Fila() {
  Node<T>* cursor = head;
  while(head) {
    cursor = cursor->getNext();
    delete head;
    head = cursor;
  }
  head = 0; // Officially empty
}

template <class T>
void Fila<T>::insertAfterLast(T dat) {
  Node<T>* p = head;
  Node<T>* q = head;

  if (head == 0)
     head = new Node<T>(dat, head);
  else {
     while (q != 0) {
        p = q;
        q = p->getNext();
     }
     p->setNext(new Node<T>(dat,0));
  }
}

template <class T>
T Fila<T>::readFirst() {
   return head->getVal(); 
}

template <class T>
T Fila<T>::removeFirst() {
  T retval = 0;
  if (head != 0){
     retval = head->getVal();
     Node<T>* oldHead = head;
     head = head->getNext();
     delete oldHead;
  }
  return retval;
}

template <class T>
void Fila<T>::listAll() {
  Node<T>* aux = head;
  while (aux != 0){
     cout << aux->getVal() << endl;
     aux = aux->getNext();
  }
}
