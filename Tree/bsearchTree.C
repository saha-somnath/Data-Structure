#include <iostream>

using namespace std;


struct Node
{
    size_t info;
    Node *leftPtr;
    Node *rightPtr;
};

class Tree
{
    
    
public:
    Node *root;
    Tree(){ root = NULL;}
    Tree(int inItem)
    { root= NULL;
       // Populate tree
    }
    ~Tree()
    {
        // free elements if root is not null
        cout<<" Destructor"<<endl;
        if ( root )
        {
           cout<<"Destroy Tree"<<endl;
           destroy( root); 
            
        }
    }
    // Create Tree
    void buildTree( Node*  rootPtr, int item);
    
    // Tree traversal
    friend void  treeTraversal( Tree);
    void preorderTraversal( Node* rootPtr );
    void inorderTraversal(Node* rootPtr);
    void postorderTraversal(Node* rootPtr );
    
    // Destroy tree
    void destroy(Node* root);
};



void Tree::buildTree(Node* rootPtr, int itemValue)
{
    
        if ( root == NULL )
        {
            rootPtr = new Node;
            rootPtr->info = itemValue;
            rootPtr->leftPtr = NULL;
            rootPtr->rightPtr = NULL;
            
            root = rootPtr;
            cout<< "Node Added:"<<rootPtr->info<<endl;
            return;
        }
    
        if ( itemValue < rootPtr->info )
        {
            cout<<"left tree"<<endl;
            if ( rootPtr->leftPtr !=NULL )
            {
                 buildTree(rootPtr->leftPtr, itemValue);
            }
            else
            {
                Node * newNodePtr =  new Node;
                newNodePtr->info = itemValue;
                newNodePtr->leftPtr = NULL;
                newNodePtr->rightPtr = NULL;
                rootPtr->leftPtr = newNodePtr;
            }
        }
        else
        {
            cout<<"right tree"<<endl;
            if (rootPtr->rightPtr !=NULL)
            {
                buildTree(rootPtr->rightPtr, itemValue);
            }
            else
            {
                rootPtr->rightPtr = new Node;
                rootPtr->rightPtr->info = itemValue;
                rootPtr->rightPtr->leftPtr = NULL;
                rootPtr->rightPtr->rightPtr = NULL;
            }
        }
    
}

// Tree Traversal

void treeTraversal( Tree myTree)
{
    cout<<"preorder Traversal"<<endl;
    myTree.preorderTraversal(myTree.root);
    cout<<"inorder Traversal"<<endl;
    myTree.inorderTraversal(myTree.root);
    cout<<"postorder Traversal"<<endl;
    myTree.postorderTraversal(myTree.root);
    
    
}

// Destroy Tree
void Tree::destroy(Node* root)
 {
    if ( root == NULL )
    {
        return;
    }
    // Delete left sub tree
    destroy(root->leftPtr);
    //cout<<"Delete NodeL:"<<root->info;
    //delete root;
    // Delete right subtree
    destroy(root->rightPtr);
    cout<<"Delete Node:"<<root->info<<endl;
    delete root;
    root = NULL;
    
}

void Tree::preorderTraversal(Node* rootPtr)
{
    // Traverse the tree
    
    if ( rootPtr == NULL )
    {
        return;
    }
    cout<<"Item:"<<rootPtr->info<<endl;
    preorderTraversal(rootPtr->leftPtr);
    preorderTraversal(rootPtr->rightPtr);
}

void Tree::inorderTraversal(Node* rootPtr)
{
    // Traverse the tree
    
    if ( rootPtr == NULL )
    {
        return;
    }
    inorderTraversal(rootPtr->leftPtr);
    cout<<rootPtr->info<<endl;
    inorderTraversal(rootPtr->rightPtr);
}

void Tree::postorderTraversal(Node* rootPtr)
{
    // Traverse the tree
    
    if ( rootPtr == NULL )
    {
        return;
    }
    
    postorderTraversal(rootPtr->leftPtr);
    postorderTraversal(rootPtr->rightPtr);
    cout<<rootPtr->info<<endl;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<"Enter Node Values"<<endl;
    Tree myTree;
    int index = 5;
    while ( index > 0 )
    {
        int value;
        cin >> value;
        
        myTree.buildTree(myTree.root, value);
        index--;
    }
    treeTraversal(myTree);
    
    return 0;
}
