/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: meghan
 *
 * 
 */


#include<iostream>
#include<string>
#include<list>
#include<new>

using namespace std;

#include"List.h"

/*
 * 
 */
int main() {
    List list;
    list.add(10);
    list.add(30);

    cout << "A List of  Values:  " << list.toString() << endl;
    //a try catch will check values at index
    // will throw an exception without this try catch statement
    try {
        cout << "Getting Value at index 0: " << list.get(0) << endl;
        cout << "Get Value at index 2: " << list.get(2) << endl;
    } catch (int ex) {
        cout << "No Index Found" << endl;
    }
    //testing insertNum function
    list.insertNum(0, 25);
    cout << "Insert value to Front of list:  " << list.toString() << endl;
    list.insertNum(1, 90);
    cout << "Insert a new Value in the List:  " << list.toString() << endl;
 \
    //testing the remove function      
    list.remove(30);
    cout << "Remove 30 from the list " << list.toString() << endl;
    list.remove(25);
    cout << "Remove 25 from the list:  " << list.toString() << endl;
    
    list.add(10);
    list.add(2);
    cout<<"new list : "<<list.toString()<<endl;
    list.clear();
    cout<<"blank List : "<<list.toString()<<endl;

    return 0;
}

