#include <iostream>
using namespace std;
struct cqueue
{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    void init (int n)
    {
        arr = new int [n];
    
        front = -1;
        rear = -1;
        size = n;

    }

    bool isempty()
    {
        if(front == -1)
            return true;
        else
            return false;

    }   

    bool isfull()
    {
        if ((rear == size-1 && front == 0)  || (front == rear +1))
            return true;
        else 
            return false;   
    }

    void insertQ(int data)
    {
        if(isfull() == true)
            return;
        else
        {
            if(front == -1)
                front++ ;
            if(rear ==  size -1)
                rear = 0;
            else
                arr[rear]=data;
        
        }
    }

    int deleteq ()
    {
        if (isempty() == true)    
            return -99999;
    
    
        int item = arr[front];
    
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            if(front == size - 1)
                front = 0;
            else
                front = front + 1;
        }   
        return item;
    }
};
int main()
{
    cqueue q1,q2;
    q1.init(10);
    q1.insertQ(5);
    cout<<q1.deleteq()<<endl;

    q2.init(10);
    q2.insertQ(20);
    cout<<q2.deleteq()<<endl;

}
