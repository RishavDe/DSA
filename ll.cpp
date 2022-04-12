#include "ll.h"


template <typename T>
Node<T>::Node(T value)
{
     next = NULL;
     data = value;
}


template <typename T>
Linkedlist<T>::Linkedlist()
{
     pthead = NULL;
}


template <typename T>
void Linkedlist<T>::push(T value)
{
   Node<T>* temp;
   temp = new Node<T>(value);
   temp->next = this->pthead;
   pthead = temp;
}


template <typename T>
void Linkedlist<T>::display()
{
    Node<T>* local;
    local = this->pthead;

    while(local!= NULL)
    {
        cout << local->data << "\t";
        local = local->next;
    }
}
