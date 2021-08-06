/*
 * Name: Tyler Kidd
 * Date Submitted: 2/1/19
 * Lab Section: 001
 * Assignment Name: Lab 2 Linked List
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  Node<T> * end;   //pointer to the last node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insert(T);
  void insertAfter(T, T);
  void insertAt(T, int);
  void priorityInsert(T, double);
  void remove(T);
  void removeAll(T);
  T getFirst();
  bool contains(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != NULL){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

  void returnFirstNode(Node<T> * iterator){
    iterator = start;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializing this list's instance variables
template <class T>
List<T>::List(){
    start = NULL;
    end = NULL;
    mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
    Node<T> *iterator = start;
    for(int i = 0; i < mySize; i++) {
        
        delete iterator;
        
        iterator = iterator->next;
    }
    
}

//Return the size of this list
template <class T>
int List<T>::size(){
    return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
    if (mySize == 0) {
        return 1;
    }
    
    else {
        return 0;
    }
}

//Create a new node with value, and insert that new node
//into this list
template <class T>
void List<T>::insert(T value){
    
     Node<T> *temp = new Node<T>(value);
    
    //if the list is null, add to the start
    if(mySize == 0) {
        cout << "init start" << endl;
        start = temp;
        end = start->next;
        
        cout << "start added" << endl;
        mySize++;
    }
    
    //otherwise add to the end
    else{
        temp->next = NULL;
        Node<T> *te = start;
        cout << "init end" << endl;
        while (te->next != NULL) {
         
         te = te->next;
        }
        te->next = temp;
        
        cout << "end added" << endl;
        mySize++;
    }
    
    // delete temp;
    
}

//Create a new node with value <value>, and insert after the first instance of
//a node with value <target>
template <class T>
void List<T>::insertAfter(T value, T target){
   
   Node<T> *temp = new Node<T>(value);
   Node<T> *previous = start;
   
    temp->value = value;
    cout << "insAfter start" << endl;
    while(previous != NULL) {
        
        if(previous->value == target) {
            
            cout << "target acquired" << endl;
            temp->next = previous->next;
            previous->next = temp;
            mySize++;
            break;
            
        }
         
         else {
             cout << "Cycle through" <<endl;
             previous = previous->next;
        }
    }
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
    
    
    Node<T> *current = start;
    Node<T> *previous = current;
    Node<T> *temp = new Node<T>(value);
    
    cout <<"insertAt start"<<endl;
    int position = 0;
    
    current = start;
    
    if(start != NULL)
  {
        while(current->next != NULL && position != j)
        {   cout<<"iterating"<<endl;
            previous = current;
            current = current->next;
            position++;
        }
        
        if(j == 0) {
         cout << "Adding at start" << endl;
         temp->next = start;
         start = temp;
         cout << "start added" << endl;
         mySize++;
        }
        
        else if(current->next == NULL && j >= position + 1)
        {
        cout << "Adding at end" << endl;
            Node<T> *te = start;
            while (te->next != NULL) {
            
            te = te->next;
            
            }
         te->next = temp;
         cout << "end added" << endl;
         mySize++;
        }

        else
        {
            previous->next = temp;
            temp->next = current;
            cout << "Node added at position " << j << endl;
            mySize++;
        }
   }
    else
    {
        start = temp;
        temp->next=NULL;
        cout << "Added at start (list was empty)" << endl;
        mySize++;
    }
}
    
//Insert into Linked List such that the list is ordered by priority
//(higher priority at beginning of list).  Should insert after all
//nodes with same priority.
template <class T>
void List<T>::priorityInsert(T value, double insertPriority){
    
    Node<T> *temp = new Node<T>(value);
    Node<T> *iterator = new Node<T>(0);
        
    cout<< "priority start" << endl;
    if (start->priority > insertPriority ) { 
        // Insert New Node before start 
        temp->next = start; 
        start = temp; 
    } 
    else { 
  
        // Traverse the list and find a 
        // position to insert new node 
        while (start->next != NULL && 
               start->next->priority < insertPriority) { 
            iterator = iterator->next; 
        } 
  
        // Either at the ends of the list 
        // or at required position 
        temp->next = start->next; 
        start->next = temp;
    } 
    
} 
    


//Remove first node whose value matches target value.
//Make no other changes to list
template <class T>
void List<T>::remove(T target){
    
    Node<T> *current = start;
    Node<T> *previous = current;
 
    
                
    cout << "remove start" << endl;
    
    while(current != NULL) {
        
        if (start->value == target) {
            Node<T> *temp = start;
            start = start->next;
            delete temp;
            mySize--;
            break;
        }
        
        else if(current->value == target) { 
            cout << "Deleting: " << current->value << "\n";
            previous->next = current->next; 
            current->next = NULL;
            delete current; // delete the node
            mySize--;
            break;
        }
    
        else if (current->value == target && current->next == NULL) {
            end = previous;
            previous->next =NULL;
            delete current;
            mySize--;
            break;
        }
        else {
            cout << "Value " << current->value << " does not match " << target << ".\n";
            previous = current;
            current = current->next;
        }
    }
     // if we reached end of list or the list is empty
        cout << "Can't remove value: no match found.\n"; 
    
    }
    

//Remove all nodes whose value is equal to target value.
//Do not change order of list (other than removing nodes)
template <class T>
void List<T>::removeAll(T target){
    
    Node<T> *current = start;
    Node<T> *previous = current;
    
    cout << "remove all start" << endl;
    while (current != NULL) {
        
        if (start->value == target) {
            cout << "delete start" << endl;
            Node<T> *temp = start;
            start = start->next;
            delete temp;
            mySize--;
        }
    
    else if(current->value == target) {
        
            cout << "delete in list" << endl;   
            previous->next = current->next; 
            current->next = NULL;
            delete current; // delete the node
            mySize--;
            current = previous;
        
    }
    else if (current->value == target && current->next == NULL) {
            cout << "delete end" << endl;
            end = previous;
            previous->next =NULL;
            delete current;
            mySize--;
            
    }
        
            previous = current;
            current = current->next;
    }
    
     if(current == NULL) { // if we reached end of list or the list is empty
        cout << "Can't remove values: no match found.\n"; 
    } 
}


//Return the value of the first node in the Linked List, and remove that node
//If no first node, return false
template <class T>
T List<T>::getFirst(){
    
    
    while(start != NULL) {
        
        return(start->value);
        break;

    }
    
    Node<T> *temp = start;
    start = start->next;
    delete temp;
    mySize--;
}


//Return true if this list contains a node whose value is equal to the key
//Otherwise, return false
template <class T>
bool List<T>::contains(T key){
    
    cout<<"contains start"<<endl;
    Node<T> *iterator = start;
    
    while (iterator != NULL) {
        
        if(iterator->value == key) {
            cout <<"found!"<<endl;
            return 1;
            break;
        }
    
        iterator = iterator->next;
    }
        cout<<"not found :("<<endl;
        return 0;
}
