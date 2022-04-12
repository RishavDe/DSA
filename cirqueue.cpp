#include <iostream>
using namespace std;
class Array
{
    int *arr;
    int size;
    public:
    Array();
    Array(int val)
    {

    }

};
class CQueue:public Array
{
    protected:
    int *arr;
    int front, rear,size;
    public:
    void init(int);
    bool isempty();
    bool isfull();
    void enqueue(int val);
    int dequeue();
};
class DCQueue:public CQueue
{
    public:
    bool compare(const CQueue&);
};
void CQueue::init(int n)
{
    size = n;
    arr = new int[n];
    front = rear= -1;
}
bool CQueue::isempty()
{
    return rear==-1;
}
bool CQueue::isfull()
{
    return (((rear == size -1) && front == 0)|| front == rear+1);
}
void CQueue::enqueue(int val)
{
    if(isfull())
    {
        cout<<"Queue full"<<endl;
        return;
    }
    if(isempty())
    {
        front  = rear = 0;

    }
    else
    {
        if( rear == size -1)
            rear =0;
        else
        rear += 1;
    }
    arr[rear] = val;
    
}
int CQueue::dequeue()
{
    if(isempty())
    { 
        cout<<"Queue empty"<<endl;
        return -19999999999999;
    }
    int item = arr[front];
    if(front == rear)
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
