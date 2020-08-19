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

/*
 Question: Given a Binary Search Tree (BST) and a range, count number of nodes that lie in the given range.
 
 Input:
         10
       /    \
     5       50
    /       /  \
  1       40   100
 Range: [5, 45]

 Output:  3
 There are three nodes in range, 5, 10 and 40
 */
void bst_node_in_range(Node* root, vector<int>& range, vector<int>& nodes)
{
    // in-order traversal.
    if(root == NULL){
        return;
    }else{
        if(range[0] <= root->data && root->data <= range[1]  ){
            bst_node_in_range(root->left, range, nodes);
            //cout<<root->data<<" ";
            nodes.push_back(root->data);
            bst_node_in_range(root->right, range,nodes);
        }else if(root->data > range[1]  ){
            bst_node_in_range(root->left, range, nodes);
        }else if(root->data  < range[0]){
            bst_node_in_range(root->right, range, nodes);
        }
    }
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

    vector<int> range({4,7});
    vector<int> range_nodes;
    Node* root = bst->getRoot();
    bst_node_in_range(root, range, range_nodes);
    cout<<"Elements in range: (4-7):";
    for(auto elm: range_nodes){
        cout<<elm<<" ";
    }
    cout<<endl;
    
    range_nodes.clear();
    nodes.clear();
    delete bst;
    return 0;
}
