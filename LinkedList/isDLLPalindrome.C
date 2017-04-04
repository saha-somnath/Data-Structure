#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;


struct Node {
  
    string data;
    Node *next;
    Node *prev;
};


Node* createNode(string& A, Node *prev, Node* next);
void display(Node* head);
bool isPalindrome(Node* firstNode, Node* lastNode);


void destroyList(Node* first);

int main(int argc, char** argv)
{
    string A [] = {"A", "B","B","A"};
    
    int size = sizeof(A) / sizeof(A[0]);
    
    // Head Node
    Node * firstNode = NULL;
    Node * lastNode  = NULL;
    
    for ( int index=0; index <size  ; index++ )
    {
        if ( firstNode == NULL )
        {
            firstNode = createNode(A[index], NULL, NULL);
            lastNode  = firstNode;
        }
        else
        {
            lastNode->next = createNode(A[index], lastNode, NULL );
            lastNode = lastNode->next; // Move to the next node
        }
    }
     
   display(firstNode);
    
    // Check is plaindrome?
    cout<<"Is Palindrome:"<< isPalindrome(firstNode, lastNode) <<endl;
    
    display(firstNode);    
    return 0;
}


Node* createNode(string & A, Node* prev, Node* next)
{
    Node* newPtr = new Node();
    newPtr->data = A;
    newPtr->next = next;
    newPtr->prev = prev;
    
    return newPtr;
}

// Is Palindrome
bool isPalindrome(Node* firstNode, Node* lastNode)
{
    while( firstNode != lastNode)
    {
        if ( firstNode->data != lastNode->data)
        {
            return 0;
        }
        firstNode = firstNode->next;
        lastNode  = lastNode->prev;
    }
    
    return 1;
}
// Display Doubly LL
void display( Node* head)
{
    Node* ptr = head;
    // Forward direction
    while( ptr != NULL )
    {
        cout<<ptr->data <<"->";
        ptr = ptr->next;
    }
    cout<<endl;
    // Backward direction
    
}

