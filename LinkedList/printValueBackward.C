#include<iostream>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;


/*
Interview Question: Facebook
If your are given an Integer Singly linked list. Print it   backwards. Constraints: 1. Do not manipulate the list.
(example: do not make it a doubly linked list, do not add or delete elements, do not change any memory location of
any element) 2. O(n) < time < O(n^2) 3. O(1) < space < O(n)

*/


struct Node
{
    int data;
    Node * next;
};

Node* createLL(int noElements)
{
    Node * head = NULL;
    Node * ptr= NULL;
    while ( noElements )
    {
        int value;
        cout<<"Enter Node Value"<<endl;
        cin>> value ;
        Node* ptrNew =  new Node();
        ptrNew->data = value;
        ptrNew->next = NULL;
        if ( head == NULL)
        {
            head = ptrNew;
            ptr = ptrNew;
        }
        ptr->next = ptrNew;
        ptr = ptr->next;
        
        noElements--;
    }
    return head;
}

void display(Node* head)
{
    Node* ptr = head;
    while( ptr != NULL )
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout<<"NULL"<<endl;
}

void reversePrint(Node* head)
{
    Node* ptr = head;
    if ( ptr ==  NULL )
        return;
    reversePrint(ptr->next);
    cout<<ptr->data << "->";
}

int main(int argc, char ** argv)
{
    Node * head;
    head = createLL(5);
    display(head);
    reversePrint(head);
    cout<<endl;
    display(head);
    return 0;
}
