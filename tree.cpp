#include<iostream>
using namespace std;
#define item int
#include"tree.h"


BinaryTree::BinaryTree()
    {
        root = NULL;
        cout<<"Default constructor called(binary tree)"<<endl;
    }

void BinaryTree:: preorder(Node* root)
{
    
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    
    
}
void BinaryTree::preorder()
{
    this->preorder(this->root);
}
void BinaryTree:: postorder(Node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    
}
void BinaryTree::postorder()
{
    this->postorder(this->root);
}
void BinaryTree:: inorder(Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    
}
void BinaryTree ::inorder()
{
    this->inorder(this->root);
}
int BinaryTree::getHeight(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int lheight = getHeight(root->left);
    int rheight = getHeight(root->right);
    return max(lheight,rheight) + 1;
}
BinarySearchTree::BinarySearchTree()
{
	root = NULL;
	cout<<"Default constructor called(bst)"<<endl;
}

Node* BinarySearchTree:: insert(Node* t, int x)
{
	if(t == NULL)
	{
		t = new Node;
		t->data = x;
		t->left = t->right = NULL;
		return t;
	}
	else if(x < t->data)
		t->left = insert( t->left,x);
	else if(x > t->data)
		t->right = insert(t->right,x);
	
}
void BinarySearchTree::insert(int val)
{
    this->root=this->insert(this->root,val);
    
}
Node* inordersucc(Node* root)
{
    Node* curr = root;
    while (curr!= NULL && curr->left!= NULL )
    {
        curr = curr->left;

    }
    return curr;
    
}
 Node* BinarySearchTree:: delNode(Node* root, item key)
	{
	if(key < root->data)
		root->left = delNode(root->left,key);
	else if(key > root->data)
		root->right = delNode(root->right,key);
	else
    {   if(root->left == NULL)
        {
            Node* temp =root->right;
            delete root;
            return temp;
        }    
        else if(root->right == NULL)
        {
            Node* temp =root->left;
            delete root;
            return temp;
        }      
        Node* temp = inordersucc(root->right);
        root->data =temp->data;
        root->right = delNode(root->right, temp->data);
    }
 }
 void BinarySearchTree::delNode(int val)
 {
     this->root=this->delNode(this->root,val);
 }
int BinaryTree:: balancedFactor(Node* root)
{
    BinaryTree bt;
    int lh = bt.getHeight(root->left);
    int rh = bt.getHeight(root->right);
    return (lh-rh);
    
}
 

Node* AVLTree::rr_rotat(Node* root)
{
    Node* temp;
    temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;

}
Node* AVLTree::ll_rotat(Node* root)
{
    Node* temp;
    temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;

   
}
Node* AVLTree::lr_rotat(Node* root)
{
    Node* temp;
    temp = root->left;
    root->left = rr_rotat(temp);
    return ll_rotat(root);
}
Node* AVLTree::rl_rotat(Node* root)
{
    Node* temp;
    temp - root->right;
    root->right = ll_rotat(temp);
    return rr_rotat(root);
}
Node* AVLTree::balance(Node* root)
{
    int bf = balancedFactor(root);
    if(bf > 1)
    {
        if(balancedFactor(root->left)>= 0)
            root = ll_rotat(root);
        else    
            root =lr_rotat(root);
    }
    else if(bf < -1 )
    {
        if(balancedFactor((root->right))>0)
            root = rl_rotat(root);
        else
            root = rr_rotat(root);
    }
    return root;
}

Node* AVLTree::insert(Node* r, int v) {
   if (r == NULL) {
      r = new Node;
      r->data = v;
      r->left = NULL;
      r->right = NULL;
      return r;
   } else if (v< r->data) {
      r->left = insert(r->left, v);
      r = balance(r);
   } else if (v >= r->data) {
      r->right = insert(r->right, v);
      r = this->balance(r);
   } return r;
}
void AVLTree::insert(int val)
{
    this->root = this->insert(this->root,val);
}
Node* SplayTree::rr_rotat(Node*)
{
    Node* temp;
    temp =root->left;
    root->left = temp->right;
    temp->right =root;
    return temp;
}
Node* SplayTree::ll_rotat(Node*)
{
    Node* temp;
    temp =root->right;
    root->right = temp->left;
    temp->left = root;
}
Node* SplayTree::Splay(Node* root, int val)
{
    if(!root)
        return NULL;
    Node* temp;
    temp->left = NULL;
    temp->right = NULL;
    Node* lmax = temp;
    Node* rmin = temp;
    while (true)
    {
        if(val < root->data)
        {
            if(!root->left)
                break;
            if(val < root->left->data)
            {
                root = rr_rotat(root);
                if(!root->left)
                    break;
            }
            rmin->left =root;
            rmin = rmin->left;
            root = root->left;
            rmin->left = NULL;
        }
        else if(val >root->data)
        {
            if(!root->right)
                break;
            if(val > root->right->data)
            {
                root = ll_rotat(root);
                if(!root->right)
                    break;
            }
            lmax->right =root;
            lmax = lmax->right;
            root = root->right;
            lmax->right = NULL;
        }
        else    
            break;
    }
    lmax->right =root->left;
    rmin->left = root->right;
    root->left = temp->right;
    root->right = temp->left;
    return root; 

}
void SplayTree::Splay(int val)
{
    this->root = this->Splay(this->root,val);
}
Node* SplayTree::insert(Node* root, int key)
{
    static Node* p_node = NULL;
    if (!p_node)
      {     
            p_node = new Node;
            p_node->data = key;
      }
      else
      {
            p_node->data = key;
            if (!root)
            {
                root = p_node;
                p_node = NULL;
                return root;
            }
            root = Splay(root, key);
            if (key < root->data)
            {
                p_node->left= root->left;
                p_node->right = root;
                root->left = NULL;
                root = p_node;
            }
            else if (key > root->data)
            {
                p_node->right = root->right;
                p_node->left = root;
                root->right = NULL;
                root = p_node;
            }
            else
                return root;
            p_node = NULL;
            return root;
        }
    
}
int main ()
{
       
        AVLTree bst;
        bst.insert(7);
        
    
        bst.insert(1);
        bst.insert(3);
        bst.insert(2);
        bst.insert(4);
        bst.insert(5);
        bst.insert(6);

        bst.preorder();
        bst.delNode(5);
        cout<<endl;
        bst.inorder();

        return 0;
        
        
        
        


    


}
