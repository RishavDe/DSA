#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
   

    Node(int value)
    {
        data = value;
        next = NULL;
    }
    

};

class List
{
    
    public:
    Node* head;
    void insertFront(Node* ,int);
    void traverse(Node*);
    void deleteHead(Node*);
    bool search(Node*,int);
    List()
    {
        cout<<"default constructor called"<<endl;
    }
    List(const List &);
    ~List();
};