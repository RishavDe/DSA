#include <iostream>
#include "Node.h"
using namespace std;
List::List(const List &l)
{
    Node* temp = l.head;
    head = new Node(temp->data);
    Node* cur = head;
    while(temp->next != NULL)
    {
        cur->next = new Node(temp->next->data);
        temp = temp->next;
        cur = cur->next;
    }
}




List::~List()
{
    Node* ptr=head;
    while(head != NULL)
    {
       
       ptr = ptr->next;
       delete ptr;
       
    }
}






void List :: insertFront(Node* head, int value)
{
    Node* N = new Node(value);
    N->next = head;
    head = N;


}
void List ::  traverse(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<endl;
}
bool List :: search(Node* head, int key)
{
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}
void List :: deleteHead(Node* head)
{
    Node* temp = head;
    head = head->next;
    delete temp;
}

int main()
{ 
    List l1;
    Node* head = NULL;
    l1.insertFront(head,1);
    l1.insertFront(head,2);
    l1.insertFront(head,3);
    
    l1.traverse(head);
    l1.deleteHead(head);
    l1.traverse(head);
    List l2;
    l2 = l1;
    l2.traverse(head);
    if(l2.search(head,2))
    
        cout<<"key found"<<endl;

    
    else
        cout<<"No key found"<<endl;
}
