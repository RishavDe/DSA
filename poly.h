#include <iostream>
using namespace std;
class Term
{
    friend class Node;
    friend class Polynomial;
    
    
    public:
    double coef;
    int exp;
    Term(){
        cout<<"Default Constructor called"<<endl;
        this->coef = 0;
        this->exp = 0;
    }
    Term (double cof,int exp)
    {
        cout<<"Parameterised Constructor called"<<endl;
        this->coef = coef;
        this->exp = exp; 
    }
    Term(const Term &o)
    {
        cout<<"Copy constructor called"<<endl;
        this->coef = o.coef;
        this->exp = o.exp;
    }

    Term operator+(const Term&) const; //add two terms.
    Term operator*(const Term&) const; //multiply two terms.
    bool operator>(const Term&) const;//compare two term according their exponent
    bool operator<(const Term&) const;//compare two term according their exponent
    bool operator==(const Term&) const;
    bool operator!=(const Term&) const;
    Term& operator=(const Term&);
    friend ostream& operator<<(ostream &out,const Term &o);
    friend istream& operator>>(istream &in,Term &o);

};
class Node
{
    friend class Polynomial;
    friend class Term;
    
    
    public:
    Term term;
    Node *next;
    Node();
    Node(Term&);
    ~Node();
    
};

class Polynomial
{
    
    friend class Term;
    friend class Node;
   
    public:
    Node *poly;
    Polynomial();
    Polynomial(const Polynomial& p);
    ~Polynomial();
    void del();
    Polynomial operator+(const Polynomial &o) const;//add two polynomials DONE
    Polynomial operator+=(const Polynomial &o);//add two polynomials and update the first operand
    void operator+=(Term &o);//add a new term at the end of the polynomial DONE
    Polynomial operator*(const Term &o) const;//multiply a term with a polynomial
    Polynomial operator*(const Polynomial &o) const;//multiply two polynomials
    Polynomial& operator=(const Polynomial &o);//overload = operator with deep copy
    friend ostream& operator<<(ostream &out,const Polynomial &o);//take input for a polynomial
    friend istream& operator>>(istream &in,Polynomial &o);//print a polynomial


};


