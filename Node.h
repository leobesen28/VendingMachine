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
class Node {

    T value;
    Node* nextNode;
    
  public:  
  	   
    Node(T value, Node* nextNode);
    T getValue();
    Node* getNextNode();
    void setValue(T value);
    void setNextNode(Node* nextNode);
    
};
