#include <iostream>
using namespace std;
  

class Node {
public:
    int data;
    Node* next;
  
    
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
  

class Linkedlist: public Node
{
    Node* head;
  
    public:
    
    Linkedlist() { head = NULL; } //constructor default
    
    void insertAtTail(int);
    void insertATHead(int);
  
    void printList();
    bool search(int);
    void deleteNode(int);
    void deletebyPos(int pos);
  
   
};
void Linkedlist::deletebyPos(int pos)
{
    if(head == NULL)
        return;
    Node* temp = head;
    
    if(pos == 0)
    {
        head = head->next;
        delete temp;
        return;
    }
    for(int i = 0;temp != NULL && i<pos -1; i++ )
        temp = temp->next;
    if(temp == NULL || temp->next == NULL)
        return;//position not found

    Node* next =  temp->next->next;
    delete temp->next;
    temp->next = next;

}
void Linkedlist::deleteNode(int value)
{
    Node* temp = head;
    if(head->data == value)
    {
        delete head;
    }
    else
    {
        while (temp->next->data == value)
        {
            temp = temp->next;
        }
        Node* temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
    }   
}
bool Linkedlist::search(int key)
{
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            return true;
            
        }
        temp = temp->next; 
        
    }
    return false;
}
void Linkedlist::insertATHead(int value)
{
    Node* newnode = new Node(value);
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        
        newnode->next = head;
        head = newnode;
    }

}
  



void Linkedlist::insertAtTail(int data)
{
    
    Node* newNode = new Node(data);
  

    if (head == NULL) {
        head = newNode;
        return;
    }
  
    // Traverse till end of list
    Node* temp = head;
    while (temp->next != NULL) {
  
        // Update temp
        temp = temp->next;
    }
  
    // Insert at the last.
    temp->next = newNode;
}
  

void Linkedlist::printList()
{
    Node* temp = head;
  

    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
  

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    Linkedlist L;
    L.insertAtTail(1);
    L.insertAtTail(2);
    L.insertAtTail(3);
    L.printList();
    L.insertATHead(4);
    L.printList();
    /*bool searchResult = L.search(3);
    if(searchResult == true)
        cout<<"Keyfound";
    else
        cout<<"Not found";
        */

    L.deletebyPos(3);
    L.printList();
    
}