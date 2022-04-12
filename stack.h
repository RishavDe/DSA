#include <iostream>
using namespace std;
class stack
{
    
    int* arr;//array
    int tos;//topmost index      
    int size;

    public:
    stack();
    stack(int);
    stack(const stack &ob);//copy constructor
    ~stack();
   

    void push(int data);
    int pop();
    
    bool isempty() ;
    bool isfull() ;




};