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
Node* insertBegin(Node* first, string & data);
void insertAfter(Node* first, string & srearchData,string& data );
Node* insertEnd(Node* last, string & data);

void destroyList(Node* first);

int main(int argc, char** argv)
{
    string A [] = {"orlando", "oviedo","miami","gainesvile"};
    
    int size = sizeof(A) / sizeof(A[0]);
    
    Node * firstNode = NULL;  // Forward pointer or node
    Node * lastNode  = NULL;  // Backward pointer or node
    
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
    
    // Insert Node at the begining
    string newVal("atlanta");
    firstNode = insertBegin(firstNode, newVal);
    // Display List
    display(firstNode);
    
    // Insert After
    
    // Insert at the end with end pointer
    cout<<"Insert Node at the end"<<endl;
    string newVal2("raleigh");
    lastNode = insertEnd(lastNode,newVal2 );
    //Display
    display(firstNode);
    
    // Insert after a node
    cout<<"Serach After a perticular Node in the list"<<endl;
    string searchvalue("oviedo");
    string newValue3("ocala");
    insertAfter(firstNode, searchvalue, newValue3 );
    // DIsplay
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

Node* insertBegin(Node* first, string & data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = first; // Assign  first Node to next pointer of new node
    // Update first Node
    first->prev   = newNode;
    return newNode;
}

// Insert at some specific position or after node
void insertAfter(Node* first, string& searchData, string & data)
{
    Node* ptr = first;
    
    while ( ptr != NULL)
    {
        // Search for data and if found , stop there
        if ( ! searchData.compare(ptr->data))
        {
            // Caeate new node
            Node * nextPtr = ptr->next;
            ptr->next = createNode(data, ptr, ptr->next);
            nextPtr->prev = ptr->next; // Update next node to point newly created node with previous pointer
            break;
        }
        ptr = ptr->next;
    }
    if (ptr == NULL )
    {
        cout<<"Search Content "<< searchData <<"Not Found in the list."<<endl;
    }
    
}


// Insert at the end
Node* insertEnd(Node* last, string& data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = last;
    last->next    = newNode;
    return newNode;
}

