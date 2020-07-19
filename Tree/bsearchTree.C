#include <iostream>
#include <vector>

using namespace std;


/*
BST Construction: For each node in a list, search (O(logN) its position and place that.
    Time complexity of constructing the BST is O(N * logN ).
Traversal: vist node as
preorder : root, left, right
inorer   : left, root, rght
postorder: left,right,root 

In traversal, each node is visted only once, hence Time Complexity O(N) for N nodes.
*/

struct Node
{
    size_t data;
    Node *left;
    Node *right;
    Node(int d=0):data(d),left(NULL),right(NULL){}
};

class BinarySearchTree
{
    Node* root;
public:
    BinarySearchTree():root(NULL){ }
    ~BinarySearchTree()
    {
        destroy( root); 
    }
    // Create BinarySearchTree
    void buildBST( Node**  rootPtr, int item);
    Node* getRoot(void) const { return root; }
    
    // BinarySearchTree traversal
    void treeTraversal(void);
    void preorder(Node* root) const;
    void inorder(Node* root) const;
    void postorder(Node* root) const;
    
    // Destroy tree
    void destroy(Node* root);
};



void BinarySearchTree::buildBST(Node** rootPtr, int value)
{
    
        if ( *rootPtr == NULL ) {
            *rootPtr = new Node(value);
            if( root == NULL ){ 
              root = *rootPtr;
            }
           
        } else if ( value < (*rootPtr)->data ) {
            buildBST(&(*rootPtr)->left, value);
        } else {
            buildBST(&(*rootPtr)->right, value);
        }
}

// BinarySearchTree Traversal

void BinarySearchTree::treeTraversal()
{
    cout<<"preorder Traversal :";
    preorder(root);
    cout<<endl;
    cout<<"inorder Traversal  :";
    inorder(root);
    cout<<endl;
    cout<<"postorder Traversal:";
    postorder(root);
    cout<<endl;
    
    
}

// Destroy BinarySearchTree
void BinarySearchTree::destroy(Node* root)
 {
    if ( root == NULL )
    {
        return;
    }
    // Delete left sub tree
    destroy(root->left);
    // Delete right subtree
    destroy(root->right);
    cout<<"Delete Node:"<<root->data<<endl;
    delete root;
    root = NULL;
    
}

// Pre-order traversal
void BinarySearchTree::preorder(Node* rootPtr) const 
{
    if ( rootPtr == NULL ) {
        return;
    }
    cout<<rootPtr->data<<" ";
    preorder(rootPtr->left);
    preorder(rootPtr->right);
}

// Inorder traversal
void BinarySearchTree::inorder(Node* rootPtr) const
{
    if ( rootPtr == NULL ) {
        return;
    }
    inorder(rootPtr->left);
    cout<<rootPtr->data<<" ";
    inorder(rootPtr->right);
}

// Pre-order traversal  
void BinarySearchTree::postorder(Node* rootPtr) const
{
    if ( rootPtr == NULL ) {
        return;
    }
    postorder(rootPtr->left);
    postorder(rootPtr->right);
    cout<<rootPtr->data<<" ";
}


int main(int argc, const char * argv[]) {
    
    vector<int> nodes({6,4,7,3,5,8});
    BinarySearchTree*  bst = new BinarySearchTree();
    for(auto value: nodes) {
        cout<<value<<" ";
        Node* ptr = bst->getRoot();
        bst->buildBST(&ptr, value);
    }
    cout<<endl;

    bst->treeTraversal();
    
    delete bst;
    return 0;
}
