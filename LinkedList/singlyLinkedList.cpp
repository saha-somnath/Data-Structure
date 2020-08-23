//
//  main.cpp
//  Test
//
//  Created by Somnath Saha on 6/24/20.
//  Copyright © 2020 Somnath Saha. All rights reserved.
//

#include <iostream>
#include <vector>
#include <assert.h>


using namespace std;

/*
Compile: g++ singlyLinkedList.cpp  -std=c++11 -o list
 
*/

template<typename T>
struct Node{
    const T data;
    Node* next;
    Node(const T d):data(d),next(NULL){};
};

template<typename T>
class LinkedList
{
    Node<T>* head;
    unsigned _size;
public:
    LinkedList():_size(0),head(NULL){};
    ~LinkedList();
    void push_back(T value);
    void display() const;
    unsigned size() const { return _size;}
    const T front() const;
    
    // Few operations on linked list
    void reverse(); //Reverse the linked list
    void sort(); // sort linked list if integer/double type
    void insert_order(T value); // Insert data in order for int,double
};

template<typename T>
LinkedList<T>::~LinkedList()
{
    if(head){
        Node<T>* ptr = head;
        while(ptr){
            Node<T>* temp = ptr;
            ptr = ptr->next;
            delete temp;
            temp= NULL;
        }
        head = NULL;
    }
}


/*
 Insert node at the end of the list
 Time Complexity: O(n)
 */
template<typename T>
void LinkedList<T>::push_back(T value)
{
    Node<T>* ptr = head;
    Node<T>* prev = head;
    if( head == NULL){
        head = new Node<T>(value);
    }else{
        while(ptr){
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = new Node<T>(value);
    }
    _size++;
}


template<typename T>
void LinkedList<T>::display() const
{
    Node<T>* ptr = head;
    while(ptr){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<"NULL"<<endl;
}

/*
 Reverse the linked list
 */
template<typename T>
void LinkedList<T>::reverse()
{
    Node<T>* curr = head;
    Node<T>* next = NULL;
    Node<T>* prev = NULL;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

/*
 Return front elment of the list.
 */
template<typename T>
const T LinkedList<T>::front() const
{
    return head->data;
}

/*
 Insert the nodes to the list in ascending order.
 */
template<typename T>
void LinkedList<T>::insert_order(T value)
{
    if(head == NULL){
        head = new Node<T>(value);
    }else{
        Node<T>* ptr = head;
        Node<T>* prev = NULL;
        while(ptr){
            if(value < ptr->data ){
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        if(prev == NULL){
            ptr = new Node<T>(value);
            ptr->next = head;
            head = ptr;
        }else{
            prev->next = new Node<T>(value);
            prev->next->next =ptr;
        }
    }
    _size++;
}

template<typename T>
void LinkedList<T>::sort()
{
    // Bubble sort
    int index = 0;
    while(index < _size){
        
        Node<T>* prev = head;
        Node<T>* curr = prev->next;
        while( curr){
            if( prev->data > curr->data){
                // Excehange nodes
                head = curr;
                prev->next = curr->next;
                curr->next = prev;
                // Update prev and curr pointer.
                curr = prev;
                prev = head;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        index++;
    }
}

int main(int argc,const char* argv[])
{
    cout<<"Test1: type=<int>"<<endl;
    LinkedList<int>* LL1 = new LinkedList<int>();
    for(auto elm: {4,6,5,7,3}){
        LL1->insert_order(elm);
    }
    LL1->display();
    cout<<"Reverse:";
    LL1->reverse();
    LL1->display();
    delete LL1;
    
    cout<<"Test2: type=<const char*>"<<endl;
    LinkedList<const char*>* LL2 = new LinkedList<const char*>();
    for(auto elm: {"a","d","c","b"}){
        LL2->push_back(elm);
    }
    assert(LL2->front() == "a");
    assert(LL2->size() == 4);
    LL2->display();
    cout<<"Reverse:";
    LL2->reverse();
    LL2->display();
    LL2->sort();
    LL2->display();
    delete LL2;
    
    cout<<"Test3: type=<double>"<<endl;
    LinkedList<double>* LL3 = new LinkedList<double>();
    for(auto elm: {4.5,6.1,3.9,7.2,3.2}){
        LL3->insert_order(elm);
    }
    LL3->display();
    cout<<"Sorted:";
    LL3->sort();
    LL3->display();
    cout<<"Reverse:";
    LL3->reverse();
    LL3->display();
    
    delete LL3;
    
    return 0;
}

