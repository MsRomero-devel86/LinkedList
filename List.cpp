
#include<iostream>
#include<string>
#include<new>



#include"List.h"
using namespace std;

/**********************************/
List::List() {
    this ->phead = nullptr;
}

/********************************/
List::~List() {
   
}
/*To traverse the list 
    // Save a pointer to the next node. // Position nodePtr at the head of the list. 
    // While nodePtr is not at the end of the list... */
void List::clear() {
    Node *pt;
    pt -> pNext = pt -> pNext;
    while(pt != nullptr){
        delete pt;
        this-> phead = pt;
       // while(pt != nullptr){
          //  this ->pt = pNext;
            delete pt;
            pt = nullptr; 
        }
    }



        
    


/*****************************/
bool List::add(int num) {
    Node *p = nullptr;
    try {
        p = new Node();
        p-> data = num;
        p-> pNext = nullptr;
        if (size() == 0) {
            this ->phead = p;
        } else {
            //create temp pointer to iterate through he list
            //assign pointer to the head of the list iter. and assign new data to end of list
            Node *pTemp = this->phead;
            Node * pTrail = pTemp;
            while (pTemp != nullptr) {
                pTrail = pTemp;
                pTemp = pTemp -> pNext;
            }
            //add the pointer trial to the end of the list 
            pTrail ->pNext = p;

        }
    } catch (bad_alloc ex) {
        cout << ex.what();
        exit(-1);
    }
    return true;
}

/*******************************/
int List::size()const {
    Node *pLength = this->phead;
    int count = 0;
    while (pLength != nullptr) {
        count++;
        pLength = pLength->pNext;
    }

    return count;
}

/***********************************/
string List::toString() {
    Node *pTemp = this->phead;
    string s = " ";
    while (pTemp != nullptr) {
        cout << pTemp-> data << "  ";
        pTemp = pTemp ->pNext;
    }

    return s;
}

/**************************************/
int List::get(int position) {
    Node *pTemp = this -> phead;

    if (position < 0 || position > size() - 1)
        throw -2;

    for (int i = 0; i < position; ++i) {
        pTemp = pTemp-> pNext;
    }

    return pTemp -> data;
}

/***************************************/
void List::remove(int position) {
    Node *pTemp;
    Node *prevNode;
    ///if list is empty return 
    if (!phead)
        return;

    if (phead ->data == position) {
        pTemp = phead -> pNext; //the 1st value will be deleted
        delete phead;
        phead = pTemp;
    } else {
        pTemp = phead;
        //skip all values that don't equal number called
        while (pTemp != nullptr && pTemp ->data != position) {
            prevNode = pTemp;
            pTemp = pTemp -> pNext;
        }
        if (pTemp) {
            prevNode -> pNext = pTemp-> pNext;
            delete pTemp;
        }

    }
}

/************************************/
bool List::insertNum(int pos, int num) {
    Node *pTemp; //pointer of temp value 
    Node * newNode = new Node(); //new node pointer, with newly created value 
    Node * ptrNode; //list pointer
    Node * prevNode = nullptr; //pervious value pointer, set to null


    newNode->data = num; //set new node as the data passed and new created obj
    //try catch statement to handle exceptions 
    try { //Because  head  is a null pointer, the condition
        //!head  is true. The statement  head = newNode;  is executed,
        //making  newNode  the first node in the list   
        if (!phead) {
            phead = newNode; //set head to new node
            newNode->pNext = nullptr; //new node is last set null after
        } else {
            ptrNode = phead; //else the pointer is head set the one before to null 
            prevNode = nullptr;

            if (pos == 0) {//if the position is 0 , check through list set value to head
                newNode ->pNext = phead;
                phead = newNode; //the head of the list is the inserted value
            } else if (pos == this->size()) {//else if the pos is the value insert the value 
                this-> add(num);
            } else {
                for (int i = 0; i <= pos; i++) {//for loop to check all node in the list 
                    if (i == pos) {
                        prevNode->pNext = newNode; //if the node is one before set the next node to the new value
                        newNode->pNext = ptrNode; //now the newNode is the value set the next value to previous node
                    }
                    prevNode = ptrNode;
                    ptrNode = ptrNode ->pNext; //point to the next node in the list 
                }
            }

        }//catch statement for memory space low 
    } catch (bad_alloc e) {
        cout << e.what();
        exit(-1);
    }//return true if the value is inserted
    return true;
}





