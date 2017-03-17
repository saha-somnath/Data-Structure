//
//  main.cpp
//  QueueUsingStack
//
//  Created by Somnath Saha on 3/16/17.
//  Copyright © 2017 Somnath Saha. All rights reserved.
//

/*
  Implementation of Queue using Stack
    - Two stack has been used to make the process faster
    - One used for enqueue operation, the other one used for dequeue operation only.
 */

#include <iostream>
#include <stack>
using namespace std;

class Queue{
    stack<int> S1; // Stack1 is used for enque
    stack<int> S2; // stack2 used for deque
    
public:
    Queue(){cout<<"New Queue"<<endl;}
    ~Queue(){};
    
    void enque(int value);
    int dequeue();
    bool isEmpty();
    
};

/*
Function Name: void Queue::enque(int value)
Description  : Enqueue element to the stack1,
*/
void Queue::enque(int value)
{
    S1.push(value);
    cout<<"Enqueued "<<value<<endl;
}

/*
 Function Name: int Queue::dequeue()
 Description  : Dequeue element from Satck2, If that is empty, get all the elements of queue from stack1. Deque operation might cost O(n) when that is empty as it has to bring elements from S1.
 */
int Queue::dequeue()
{
    // Check if Queue is empty, then throw errors
    if ( isEmpty() )
    {
        cout<<"ERROR: Queue is empty!"<<endl;
        return -1;
    }
    // Take everything from S1 to S2 if S2 is empty
    if (S2.empty())
    {
        // Check S1 if that has elements
        while(! S1.empty())
        {
            S2.push(S1.top());
            S1.pop(); // Pop the element
        }
    }
    
    
    
    int frontValue = S2.top();
    S2.pop();
    
    return frontValue;
}

/*
Function Name: bool Queue::isEmpty()
Description  : Check if the Queue empty?
*/

bool Queue::isEmpty()
{
    if ( S1.empty() && S2.empty())
    {
        return true;
    }
    return false;
}


int main(int argc, const char * argv[]) {
    
    // Craete Queue
    Queue Q;
    
    // Push element.
    cout<<"Enqueue Operation:"<<endl;
    Q.enque(10);
    Q.enque(5);
    Q.enque(20);
    // Normal dequeue operation
    cout<<"Dqueue Operation:"<<Q.dequeue()<<endl;
    cout<<"Dqueue Operation:"<<Q.dequeue()<<endl;
    
    Q.enque(11);
    Q.enque(28);
    
    // Check Normal dequeue
    cout<<"Dqueue Operation:"<<Q.dequeue()<<endl;
    cout<<"Dqueue Operation:"<<Q.dequeue()<<endl;
    cout<<"Dqueue Operation:"<<Q.dequeue()<<endl;
    
    // Enque ellement
    Q.enque(12);
    cout<<"Dqueue Operation:"<<Q.dequeue()<<endl;
    // Check for dequeue operation on empty Queue
    cout<<"Dqueue Operation:"<<Q.dequeue()<<endl;

    return 0;
}

