//
//  main.cpp
//  Queue
//
//  Created by Somnath Saha on 5/5/20.
//  Copyright © 2020 Somnath Saha. All rights reserved.
//

/*
 Compile:
 g++ TemplatedQueue.cpp -std=c++11
 Execution:
 ./a.out
*/

#include <iostream>
#include <mutex>

using namespace std;
// Templated Function

mutex mtx;

template <class T>
struct Node
{
  T data;
  Node* next;
};

template <class T>
class Queue
{
  Node<T>* f; // Front pointer
  Node<T>* r; // rear pointer
  uint32_t _size;
public:
  Queue():f(NULL),r(NULL),_size(0){ }
  ~Queue(){
    if( f){
      while(f){
        Node<T>* ptr = f;
        f = f->next;
          cout<<"Destroying data:"<<ptr->data<<endl;
        delete ptr;
      }
      r = NULL;
    }
  }
  
  // Operations
  void push(const T&);
  void pop();
  bool empty();
  uint32_t size();
  T& front() const;
  T& back() const;
};


template <class T>
void Queue<T>::push(const T& data)
{
    Node<T>* node = new Node<T>();
    node->data = data;
    node->next= NULL;
    std::unique_lock<mutex> lck(mtx);
    if(r == NULL){
        r = node;
        f = r;
    } else {
        r->next = node;
        r = node;
    }
    _size++;
}


template <class T>
bool Queue<T>::empty()
{
    std::unique_lock<mutex> lck(mtx);
    if( f == NULL && r == NULL ){
        return true;
    }
    return false;
}

template <class T>
void Queue<T>::pop()
{
    std::unique_lock<mutex> lck(mtx);
    cout<<"DEBUG: pop - "<<f->data<<endl;
    Node<T>* ptr = f;
    f = f->next;
    delete ptr;
}

template <class T>
uint32_t Queue<T>::size()
{
    std::unique_lock<mutex> lck(mtx);
    return _size;
}

template <class T>
T& Queue<T>::front() const
{
    std::unique_lock<mutex> lck(mtx);
    return f->data;
}

template <class T>
T& Queue<T>::back() const
{
    std::unique_lock<mutex> lck(mtx);
    return r->data;
}

int main(int argc, const char * argv[]) {
    
    cout<<"Queue using Template:"<<endl;
    
    Queue<int>* q1 = new Queue<int>();
    q1->push(10);
    q1->push(11);
    q1->push(12);
    cout<<"Queue Size:"<<q1->size()<<endl;
    cout<<"Queue Front Element:"<<q1->front()<<endl;
    cout<<"Queue Back Element:"<<q1->back()<<endl;
    q1->pop();
    cout<<"Queue Front Element:"<<q1->front()<<endl;
    delete q1;
    
    Queue<char>* q2 = new Queue<char>();
    
    q2->push('a');
    q2->push('b');
    q2->push('c');
    cout<<"Queue Size:"<<q2->size()<<endl;
    
    cout<<"Queue Front Element:"<<q2->front()<<endl;
    cout<<"Queue Back Element:"<<q2->back()<<endl;
    q2->pop();
    cout<<"Queue Front Element:"<<q2->front()<<endl;
    delete q2;

    return 0;
}

