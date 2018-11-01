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

#include "Node.h"


template <class T>
Node<T>::Node(T value, Node* nextNode){
       this->value = value;
       this->nextNode = nextNode;
}


template <class T>
T Node<T>::getValue(){
     return value;
}


template <class T>
Node<T>* Node<T>::getNextNode(){
     return nextNode;
}


template <class T>
void Node<T>::setValue(T value){
     this->value = value;
}


template <class T>
void Node<T>::setNextNode(Node* nextNode){
       this->nextNode = nextNode;
}

