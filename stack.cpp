#include<iostream>
#include "stack.h"
using namespace std;
stack::stack(){
	cout<<"default constructor"<<endl;
	arr=new int[10];
	tos=-1;
	size=10;
	//this++;
}
stack::stack(int size)
{
	cout<<"parameterized constructor"<<endl;
	arr=new int[size];
	tos=-1;
	this->size=size;
}
stack::stack(const stack &ob)
{
	//arr=ob.arr;//shallow copy
	arr=new int[ob.size];
	tos=ob.tos;
	size=ob.size;
	for(int i=0;i<tos;i++)//deep copy
		arr[i]=ob.arr[i];
}
stack::~stack()
{
	delete[] arr;
}	
void stack::push(int data)
{
	if(tos!=size-1)
		arr[++tos]=data;
}
int stack::pop()
{
	if(tos!=-1)
		return arr[tos--];
}

bool stack::isempty()  
{
	return tos==-1;
}
bool stack::isfull() 
{
	return tos==size-1;
}