#include<iostream>
using namespace std;



template <typename T>
class Node
{
    T data;
    Node<T>* next;
    public:
          Node(T value);
          friend class Linkedlist<T>;
};

template <typename T>
class Linkedlist 
{
    Node<T>* pthead;
    public:
    Linkedlist();
    void push(T value);
    void display();
};


/*int main()
{
     Linkedlist<int> list;
     list.push(34);
     list.push(32);
     list.push(89);

     list.display();
     return 0;
}*/