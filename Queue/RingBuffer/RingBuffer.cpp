//
//  main.cpp
//  RingBuffer
//
//  Created by Somnath Saha on 5/27/20.
//  Copyright © 2020 Somnath Saha. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>

#define assertm(exp, msg) assert(((void)msg, exp))

/*
  Compilation: g++ RingBuffer.cpp -o RingBuffer
  Execution:./RingBuffer
 
  Testing of RingBuffer
 */

using namespace std;

class RingBuffer
{
    int _front;
    int _rear;
    const uint32_t _size;
    int* _buffer;
    uint32_t _element_count;
public:
    RingBuffer(uint32_t size=10):_size(size)
    {
        _buffer = new int[size];
        _front  = -1;
        _rear   = -1;
        _element_count = 0;
    }
    ~RingBuffer()
    {
        if(_buffer){
            delete [] _buffer;
        }
    }
    
    uint32_t size() const { return _size; }
    bool empty() const;
    int front(void) const;
    int rear(void) const;
    void pop();
    void push_back(int value);
    void display() const;
    uint32_t element_count(void) const { return _element_count;}
};

/*
 Function Name: empty()
 Description: Check if RingBuffer is empty
 Return: <bool> True/False, Empty/Not Empty
*/
bool RingBuffer::empty() const
{
    
    if(_front == -1){
        return true;
    }
    return false;
}

/*
 Function Name: front()
 Description: Return front elements if RingBuffer not empty
 Return: <int>  Front element.
*/
int RingBuffer::front() const
{
    if(!empty()){
        return _buffer[_front];
    } else{
        cout<<"ERROR: Buffer is empty ... "<<endl;
    }
    return -1;
}

/*
 Function Name: rear()
 Description: Return rear elements if RingBuffer not empty
 Return: <int>  Rear element.
*/
int RingBuffer::rear() const
{
    if(!empty()){
        return _buffer[_rear];
    } else{
        cout<<"ERROR: Buffer is empty ... "<<endl;
    }
    return -1;
}

/*
 Function Name: pop()
 Description: Pop element if RingBuffer not empty
 Return: None.
*/
void RingBuffer::pop()
{
    if(!empty()){
        _buffer[_front] = -1;
        if(_front == _rear){
            _front = -1; // If the buffer has only one element left.
        }else if ( _front == _size -1){
            _front = 0; // if front is the last element of array
        } else{
            _front++; // Increment front for normal condition
        }
        _element_count--; // reduce the elemnt count
    } else {
        cout<<"ERROR: Buffer is empty ...!"<<endl;
    }
}

/*
 Function Name: push_back()
 Description: Add passed element if RingBuffer not full.
 Input Args: <int> value
 Return: None.
*/
void RingBuffer::push_back(int value)
{
    if( _element_count == _size) {
        cout<<"WARNING: Buffer is full!\n";
    } else {
        // Increment rear
        if(_rear == -1){
            _rear = _front = 0; // First element
        }else if (empty()){
            _front = _rear;
        }else if( _rear == _size -1){
            _rear = 0; // Reached last element, moving to first index.
        }else{
            _rear++;
        }
        //cout<<"Value:"<<value<<" Front:"<<_front<<" Rear:"<<_rear<<endl;
        _buffer[_rear] = value;
        _element_count++; // Increase element count.
    }
}

int main(int argc, const char * argv[]) {
    
    std::cout << "Ring Buffer - A circular Queue - \n\n";
    
    cout<<"*** Push a element and Pop it ***\n";
    RingBuffer* R1 = new RingBuffer( 10 );
    cout<<" >> Pushed element 10 to RingBuffer\n";
    R1->push_back(10);
    assert(R1->front() == 10); // Check front() function
    cout<<"Test1: PASSED : front element is 10\n";
    assert(R1->rear() == 10); // Check front() function
    cout<<"Test2: PASSED : rear element is 10\n";
    cout<<" >> Pop element \n";
    R1->pop();
    cout<<"Test3: PASSED : Empty Ring Buffer\n";
    assert(R1->empty());
    //assertm(R->empty(), "Checking Empty RingBuffer");
    //static_assert((R->empty()), "Empty RingBuffer");
    delete R1;
    
    /*
     Fill up complete Ring Buffer and perform following checks
     - Buffer Size is same element counts
     - Pop all elements and check if Ring Buffer is empty?
     */
    cout<<"\n*** Fillup Complete Buffer ***\n";
    RingBuffer* R2 = new RingBuffer(5);
    for(int index = 0; index < 5; index++ ){
        R2->push_back(index);
    }
    assert(R2->front() == 0); // Check front() function
    cout<<"Test4: PASSED : front element is 0\n";
    assert(R2->size() == R2->element_count());
    cout<<"Test5: PASSED : Ring Buffer Size == Element Counts\n";
    assert(! R2->empty());
    cout<<" >> Pop Up all elemnets ...\n";
    for(int index=0; index<5; index++){
        cout<<R2->front()<<" ";
        R2->pop();
    }
    cout<<endl;
    assert(R2->empty());
    cout<<"Test6: PASSED : Empty Ring Buffer\n";
    delete R2;
    
    /*
     Testing overflow of element.
     A warning messge is printed and new elements are skipped.
     */
    cout<<"\n*** Testing of Buffer Overflow ***\n";
    RingBuffer* R3 = new RingBuffer(5);
    for(int index = 0; index < 6; index++ ){
        R3->push_back(index);
    }
    
    assert(R3->size() == R3->element_count());
    cout<<"Test7: PASSED : Buffer Size is same as Total Elements\n";
    // Remove element and insert
    cout<<" >> Removed Element:"<<R3->front()<<endl;
    R3->pop();
    
    assert(R3->size() > R3->element_count());
    cout<<"Test8: PASSED : Buffer Size > Total Elements\n";
    R3->push_back(10);
    cout<<" >> Enqueued Element:"<<R3->rear()<<endl;
    assert(R3->rear() == 10);  // Check data functionality of rear()
    cout<<"Test9: PASSED : Elements is 10 \n";
    assert(R3->size() == R3->element_count());
    cout<<"Test10: PASSED : Buffer Size == Total Elements \n";
    delete R3;
    return 0;
}

