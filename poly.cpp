#include <iostream>
#include "poly.h"
using namespace std;
Node::Node(Term& t)
{
    this->term.coef = t.coef;
    this->term.exp = t.exp;
    this->next = NULL;
}

 ostream& operator<<(ostream &out,const Term &o)
 {
     out<<endl<<o.coef<<"x^"<<o.exp;
     return out;
 }
 istream& operator>>(istream &in,Term &o)
 {
     cout<<"Enter coefficient and exponent"<<endl;
     in>>o.coef>>o.exp;
     return in;
 }
 ostream& operator<<(ostream &out,const Polynomial &o)
 {
    while (o.poly != NULL)
    {
        cout<<o.poly->term;
        *o.poly = *o.poly->next;
    }
    
     
 }
 istream& operator>>(istream &in,Polynomial &o)
 {
     char choice;
     o.poly = new Node(o.poly->term);
    while(true)
    {
        cout<<"Enter y to enter new value and n to complete"<<endl;
        if(choice == 'y')
        {
            cin>>o.poly->term;
            
        }   
        else if(choice == 'n')
            break;

    }
 }
Term Term ::operator+(const Term& t1) const
{
    Term res;
      
    res.coef = t1.exp + this->coef;
    res.exp = t1.exp;
    return res;
    
}
Term Term :: operator*(const Term& t1) const
{
    Term res;
    res.coef = this->coef * t1.coef;
    res.exp = this->exp + t1.exp;
    return res;
}
void Polynomial:: operator+=(Term &o)
{
    while(this->poly->next != NULL)
    {
        this->poly = this->poly->next;
    }
    this->poly->next->term = o;
    
    
}
Polynomial Polynomial:: operator+(const Polynomial &o) const
{
    Polynomial res;
    Term temp;
    while(o.poly != NULL && this->poly != NULL)
    {
        if (this->poly->term.exp > o.poly->term.exp)
        {
            res += this->poly->term;
            *this->poly = *this->poly->next;
                    
        }
        else if (this->poly->term.exp < o.poly->term.exp)
        {
            res += o.poly->term;
            *o.poly = *o.poly->next;

        }
        else
        {
            temp = this->poly->term + o.poly->term;
            res += temp;
            *this->poly = *this->poly->next;
            *o.poly = *o.poly->next;
        }
        
        return res;
         
       
    }
}
