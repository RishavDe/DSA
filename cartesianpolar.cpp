#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
class Polar;
class Cartesian;
class Cartesian
{
    public:
    int x;
    int y;
   
    Cartesian()
    {
        x = 0;
        y = 0;

    }
    Cartesian(int a, int b)
    {
        x = a;
        y = b;
    }
    Cartesian(const Cartesian& c1)
    {
        this->x = c1.x;
        this->y = c1.x;
    }
    Cartesian(Polar p)
    {
        x = p.r * cos(p.angle);
        y = p.r * sin(p.angle);
    }
    int operator-(const Cartesian) const;
    bool operator==(const Cartesian) const;
    friend bool operator==(Cartesian,Polar);
};
class Polar
{
    public:
    int r;
    double angle;
    
    Polar()
    {
        r = 0;
        angle = 0;
    }
    Polar(int x, int theta)
    {
        r = x;
        angle = theta;
        
    }
    Polar(const Polar& c1)
    {
        this->r  = c1.r;
        this->angle = c1.angle;

    }
    Polar(Cartesian c)
    {
        this->r = sqrt(pow(c.x,2) + pow(c.y,2));
        this->angle = atan(c.y/c.x);
    }
    int operator-(const Polar) const;
    bool operator==(const Polar) const;
    friend bool operator==(Cartesian,Polar);
    
    
};

int Cartesian::operator-(const Cartesian c1) const
{
    return (int)sqrt(pow(this->x - c1.x , 2) +  pow(this->y - c1.y, 2)) ;
}

int Polar::operator-(const Polar p1) const
{
    return (int)sqrt(pow(this->r,2) + pow(p1.r,2) + (2.0 * this->r * p1.r * cos(this->angle - p1.angle)));
}
//
bool Cartesian::operator==(const Cartesian c1) const
{
    if (this->x == c1.x && this->y == c1.y)
    {
        return true;
    }
    else
        return false;
}
bool Polar::operator==(const Polar p1) const
{
    if(this->r == p1.r && this->angle == p1.angle)
        return true;
    else
        return false;
}
bool operator==(Cartesian c,Polar p)
{
    if(sqrt(pow(c.x,2)+pow(c.y,2)) == p.r && cos(p.angle) == (c.x/sqrt(pow(c.x,2) + pow(c.y,2))) )
    {
        return true;
    }
    else 
        return false;
}
int main()
{
    Cartesian c1(2,3),c2(10,50),c3;
    //cout<<(c1 - c2)<<endl;
    Polar p1(10,20), p2(4,30),p3;
    //cout<<(p1-p2)<<endl;
    bool res = c1 == c2;
    /*if(res==true)
        cout<<"Equal";
    else
        cout<<"Unequal";*/

    c3 = p1;
    p3 = c2;
    cout<<c3.x<<" "<<c3.y<<endl;
    cout<<p3.r<<" "<<p3.angle;
    if(c1 == p1)
    {
        cout<<"Equal";
    }
    else
    {
        cout<<"Unequal";
    }

    return 0;
}
