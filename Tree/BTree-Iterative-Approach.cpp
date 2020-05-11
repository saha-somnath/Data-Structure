//
//  BTree-Iterative-Approach.cpp
//  Tree
//
//  Created by Somnath Saha on 5/9/20.
//  Copyright © 2020 Somnath Saha. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/*
 Input :
            10
           /  \
          20   30
         / \   / \
        40 50 60  70
  
 BTree Height:3
 BTree Left View:10,20,40
 BTree Right View:10,30,70
 BTree Left View Sum:70
 
 Input :
             10
            /  \
           12    5
          /     / \
         2     6  14
                \
                 9
 BTree Height:4
 BTree Left View:10,12,2,9
 BTree Right View:10,5,14,9
 BTree Left View Sum:33
 BTree laef nodes:2,14,9
 BTree preorder traversal:10,12,2,5,6,9,14
 BTree inorder traversal:2,12,10,6,9,5,14
 BTree postorder traversal:2,12,9,6,14,5,10

Compile: g++ BTree-Iterative-Approach.cpp -std=c++11
 */

struct Node
{
    int _data;
    Node* left;
    Node* right;
    Node(int data = 0):_data(data),left(NULL),right(NULL){}
};

class BTree
{
    Node* _root;
public:
    BTree(Node* r = NULL):_root(r){}
    ~BTree()
    {
        clear();
    }
    void set_root(Node* node) { _root = node; }
    Node* get_root() const { return _root; }
    void display() const;
    
    // Iterative approach
    void clear();
    void left_view() const;
    void right_view() const;
    int sum_left_view_nodes() const;
    uint32_t height() const;
    void leaf_nodes() const;
    //Traversal -Iterative approach.
    void preorder() const;
    void inorder() const;
    void postorder() const;
    
};



/*
 Display left most nodes.
 Iterative Approach based on queue.
 */
void BTree::left_view() const
{
    Node* ptr = _root;
    queue<Node*> Q;
    if(ptr){
        Q.push(ptr);
        Q.push(NULL);
        // Check each level
        while(!Q.empty()){
            Node* temp = Q.front();
            if(temp){
                cout<<temp->_data<<",";
                // Enque childern
                while(temp){
                    // left node
                    if(temp->left){
                        Q.push(temp->left);
                    }
                    // Right node
                    if(temp->right){
                        Q.push(temp->right);
                    }
                    Q.pop();
                    temp = Q.front();
                }
                Q.push(NULL); // Seperator each lavel
            }
            Q.pop(); // Remove NULL element
        }
        cout<<endl;
    }
}

/*
 Display right view of BTree.
 Iterative Approach based on queue.
 */
void BTree::right_view() const
{
    Node* ptr = _root;
    queue<Node*> Q;
    if(ptr){
        Q.push(ptr);
        Q.push(NULL);
        // Check each level
        while(!Q.empty()){
            Node* temp = Q.front();
            Node* prev = NULL;
            if(temp){
                while(temp){ // Enque childern
                    if(temp->left){ // left node
                        Q.push(temp->left);
                    }
                    if(temp->right){ // Right node
                        Q.push(temp->right);
                    }
                    prev = temp;
                    Q.pop();
                    temp = Q.front();
                }
                cout<<prev->_data<<",";
                Q.push(NULL); // Seperator each lavel
            }
            Q.pop();
        }
        cout<<endl;
    }
}

/*
 Summmation of node value of all left view node.
 */
int BTree::sum_left_view_nodes() const
{
    int sum = 0;
    Node* ptr = _root;
    queue<Node*> Q;
    if(ptr){
        Q.push(ptr);
        Q.push(NULL);
        // Check each level
        while(!Q.empty()){
            Node* temp = Q.front();
            if(temp) {
                //cout<<temp->_data<<",";
                sum += temp->_data;
                // Enque childern
                while(temp){
                    // left node
                    if(temp->left){
                        Q.push(temp->left);
                    }
                    // Right node
                    if(temp->right){
                        Q.push(temp->right);
                    }
                    Q.pop();
                    temp = Q.front();
                }
                Q.push(NULL); // Seperator each lavel
            }
            Q.pop();
        }
    }
    return sum;
}

/*
 Iterative approach of calculating height.
 */
uint32_t BTree::height() const
{
    uint32_t h = 0;
    Node* ptr = _root;
    queue<Node*> Q;
    if(ptr){
        Q.push(ptr);
        Q.push(NULL);
        // Check each level
        while(!Q.empty()){
            Node* temp = Q.front();
            if( temp) {
                h +=1; // Height count
                // Enque childern
                while(temp){
                    // left node
                    if(temp->left){
                        Q.push(temp->left);
                    }
                    // Right node
                    if(temp->right){
                        Q.push(temp->right);
                    }
                    Q.pop();
                    temp = Q.front();
                }
                Q.push(NULL);
            }
            Q.pop(); // Remove NULL
        }
    }
    return h;
}

/*
 Clear all elements of BTree
 */
void BTree::clear()
{
    Node* ptr = _root;
    queue<Node*> Q;
    if(ptr){
        Q.push(ptr);
        Q.push(NULL);
        
        // Check each level
        while(!Q.empty()){
            Node* temp = Q.front();
            if(temp) {
                // Enque childern
                while(temp){
                    // left node
                    if(temp->left){
                        Q.push(temp->left);
                    }
                    // Right node
                    if(temp->right){
                        Q.push(temp->right);
                    }
                    Q.pop();
                    delete temp;
                    temp = Q.front();
                }
                Q.push(NULL); // Seperator each lavel
            }
            Q.pop();
        }
    }
    _root = NULL;
}

void BTree::display() const
{
    Node* ptr = _root;
    queue<Node*> Q;
    if(ptr){
        Q.push(ptr);
        Q.push(NULL);
        // Check each level
        while(!Q.empty()){
            Node* temp = Q.front();
            if( temp) {
                cout<<"(";
                // Enque childern
                while(temp){
                    cout<<temp->_data;
                    // left node
                    if(temp->left){
                        Q.push(temp->left);
                    }
                    // Right node
                    if(temp->right){
                        Q.push(temp->right);
                    }
                    Q.pop();
                    temp = Q.front();
                    if (temp) {
                        cout<<",";
                    }
                }
                cout<<")"<<endl;
                Q.push(NULL);// Seperator each lavel
            }
            Q.pop();
        }
    }
}

/*
 Leaf Nodes
 */
void BTree::leaf_nodes() const
{
    Node* ptr = _root;
    queue<Node*> Q;
    if(ptr){
        Q.push(ptr);
        Q.push(NULL);
        // Check each level
        while(!Q.empty()){
            Node* temp = Q.front();
            Node* prev = NULL;
            if(temp){
                while(temp){ // Enque childern
                    if(temp->left){ // left node
                        Q.push(temp->left);
                    }
                    if(temp->right){ // Right node
                        Q.push(temp->right);
                    }
                    if( temp->left == NULL && temp->right == NULL){
                        cout<<temp->_data<<",";
                    }
                    prev = temp;
                    Q.pop();
                    temp = Q.front();
                }
                Q.push(NULL); // Seperator each lavel
            }
            Q.pop();
        }
        cout<<endl;
    }
}

/*
 Preorder Traversal based on iterative appraoch.
 root, left, right
 Use a stack to insert, root, then right child, the left child.
 */
void BTree::preorder() const
{
    if(_root){
        stack<Node*> S;
        S.push(_root);
        while(! S.empty()){
            Node* temp = S.top();
            cout<<temp->_data<<",";
            S.pop();
            if(temp->right){ // Insert right child first for LIFO property
                S.push(temp->right);
            }
            if(temp->left){
                S.push(temp->left);
            }
        }
        cout<<endl;
    }
    
}

/*
 Inorder Traversal based on iterative appraoch.
 left, root, right
 Use a stack to insert, root, then right child, the left child.
 */
void BTree::inorder() const
{
    if(_root){
        stack<Node*> S;
        //S.push(_root);
        Node* temp = _root;
        while(temp || ! S.empty()){
            while( temp ){ // Insert all left child
                S.push(temp);
                temp = temp->left;
            }
            temp = S.top();
            S.pop();
            cout<<temp->_data<<",";
            temp = temp->right;
        }
        cout<<endl;
    }
}

/*
 Post Traversal based on iterative appraoch.
 left, right, root
 Step1: Use a stack to push all lest most elements
 Step2: if root has right, push right too.
 Follow step1
 */
void BTree::postorder() const
{
    if(_root){
        stack<Node*> S1;
        stack<Node*> S2;
        S1.push(_root);
        while(! S1.empty()){
            Node* temp = S1.top();
            S2.push(temp);
            S1.pop();
            if ( temp->left){
                S1.push(temp->left);
            }
            if( temp->right){
                S1.push(temp->right);
            }
        }
        while(! S2.empty()){
            Node* temp = S2.top();
            cout<<temp->_data<<",";
            S2.pop();
        }
        cout<<endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "BTree a iterative approach...\n";
    Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(5);
    root->left->left =  new Node(2);
    root->right->left =  new Node(6);
    root->right->right =  new Node(14);
    root->right->left->right =  new Node(9);
    BTree* T = new BTree(root);

    // Display
    T->display();
    // height
    cout<<"BTree Height:"<<T->height()<<endl;
    // Left view
    cout<<"BTree Left View:";
    T->left_view();
    // Right view
    cout<<"BTree Right View:";
    T->right_view();
    // Left view node sum
    cout<<"BTree Left View Sum:"<<T->sum_left_view_nodes()<<endl;
    // Leaf Nodes
    cout<<"BTree laef nodes:";
    T->leaf_nodes();
    // Preorder
    cout<<"BTree preorder traversal:";
    T->preorder();
    // Inorder
    cout<<"BTree inorder traversal:";
    T->inorder();
    // Postorder Traversal
    cout<<"BTree postorder traversal:";
    T->postorder();
    
    delete T;
    return 0;
}

