#include <iostream>
using namespace std;
class Complex
{
    public:

    int real;
    int imag;
    
    Complex()
    {
       
        cout<<"Default constructor";
    }
    Complex(int a, int b)
    {

        real = a;
        imag = b;
        
    }
    Complex operator+(Complex c)
    {
        Complex c3;
        c3.real = real + c.real; 
        c3.imag = imag + c.imag;
        return c3;
        
    }
    Complex operator*(Complex c)
    {
        Complex c2;
        c2.real = (real * c.real) - (imag * c.imag);
        c2.imag = (real * c.imag) + (imag * c.real);
        return c2;
    }
};
int main()
{
    Complex c1(2,3),c2(4,5);
    Complex c3;
    c3 = c1 + c2;
    cout<<c3.real<<" + i"<<c3.imag;
    
    return 0;
}