//
//  main.cpp
//  TempDS
//
//  Created by Somnath Saha on 3/10/17.
//  Copyright © 2017 Somnath Saha. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;


/* Some Interview Question On Tree
   1. Left sum of nodes: Update node value with their left sub-tree sum
      10              20
    /    \          /    \
    5     6    =>   8     6
   / \             / \
   3 2             3 2
 
   2. Find the deepest node
    - Use level order traversal using queue
 
*/
// Node Structure
struct Node
{
    int value;
    Node * left;
    Node * right;
};

// Create Node
Node* createNode(int value)
{
    Node* ptr = new Node();
    ptr->value = value;
    ptr->left = NULL;
    ptr->right = NULL;
    
    return ptr;
}

// 1. Find sum of left branch and update to the parent. Based on inorder traversal
int leftSum( Node * ptr)
{
    if( ptr == NULL)
    {
        return 0;
    }
    
    // Left node first
    ptr->value += leftSum(ptr->left);
    return ptr->value + leftSum(ptr->right);
}

// Display based on inorder traversal
void inorder( Node * ptr)
{
    if (ptr == NULL)
    {
        return ;
    }
    
    inorder(ptr->left);
    cout<<ptr->value <<"->";
    inorder(ptr->right);
    
}

//2. Deepest Node in the Tree, level order traversal
int deepestNode( Node* root)
{
    // Return if root null
    if ( root == NULL)
    {
        return 0;
    }
    // Push first node to the Queue
    queue<Node*> Q;
    Q.push(root);
    Node* ptr = NULL;
    
    while( ! Q.empty())
    {
        // Dequeue element
        ptr = Q.front();
        Q.pop();
        // Enqueue left and right nodes
        if ( ptr->left)
        {
            Q.push(ptr->left);
        }
        if (ptr->right)
        {
            Q.push(ptr->right);
        }
    }
    
    return ptr->value;
}


int main()
{
    Node* root = createNode( 10);
    root->left = createNode(5);
    root->right = createNode(6);
    root->left->left = createNode(3);
    root->left->right = createNode(2);
    //root->left->right->left = createNode(1);
    
    // Display Tree
    inorder(root);
    cout<<endl;
    // Left sum
    leftSum(root);
    
    // Inorder
    inorder(root);
    cout<<endl;
    
    // Deepest Node , based on level order traversal
    cout<<"Deepest Node Based on Level Oreder Traversal:"<<deepestNode(root)<<endl;
    
    
    return 0;
}

