#include<iostream>
using namespace std;
#define item int
class Node
{
    public:
        item data;
        Node* left;
        Node* right;
        public:
        
        
    friend class BinaryTree;
    friend class BinarySearchTree;
    friend class AVLTree;
};
class BinaryTree
{
	protected:
    Node* root;
    void preorder(Node*);
    void postorder(Node*);
    void inorder(Node*);
    int getHeight(Node*);
    
   public:
 
    BinaryTree();
    
    
   
    int balancedFactor(Node*);
   
    void preorder();
    void postorder();
    void inorder();
    int getHeight();
    virtual void insert(int val){};

};
class BinarySearchTree:public BinaryTree
{
    //Node *root;
    
     Node* insert(Node* root, item val);
     Node* delNode(Node* root, item term);
    public:
   
    BinarySearchTree();
    

    
  
    virtual void insert(item val);
    void delNode( item term);
};

class AVLTree : public BinarySearchTree
{
    //Node* root;
    virtual Node* rr_rotat(Node*);
    virtual Node* ll_rotat(Node*);
    virtual Node* lr_rotat(Node*);
    virtual Node* rl_rotat(Node*);
    Node* insert(Node*,int);
     Node* balance(Node*);
    
    public:
    
   
    void insert(int val);
   
};
class SplayTree: public BinarySearchTree
{
    Node* Splay(Node*,int );
    Node* rr_rotat(Node*);
    Node* ll_rotat(Node*);
    Node* lr_rotat(Node*);
    Node* rl_rotat(Node*);
    Node* insert(Node* ,int);
    public:
    void Splay(int val);
    void insert(int);

};
