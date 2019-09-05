
/* 
 * File:   List.h
 * Author: meghan
 *
 * 
 */

#ifndef LIST_H
#define LIST_H
#include<string>

using namespace std;

struct Node{
    int data;
    Node *pNext;
};
class List{
private:
    Node* phead;
public:
    List();
    ~List();
    bool add(int);
    void remove(int position);
    int get(int position);
    int size()const;
    string toString();
    bool insertNum(int pos, int num);
   void clear();
  
};


#endif /* LIST_H */

