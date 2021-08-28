#pragma once
#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;

const double PI = 3.14159265;

class Complex
{
    float a, b;
    friend class Calc;

public:
    Complex(float, float);
    void setNumber(float, float);
    void print(void);
    Complex conjugate(void);
    double arg(string);
};

// Constructor
Complex::Complex(float x = 0, float y = 0)
{
    a = x;
    b = y;
}

// Sets a and b from outside
void Complex::setNumber(float x, float y)
{
    a = x;
    b = y;
}

// Prints in nice format
void Complex::print(void)
{
    if (b < 0)
    {
        cout << a << b << "j" << endl;
    }
    else
    {
        cout << a << "+" << b << "j" << endl;
    }
}

// Find conjugate
Complex Complex::conjugate(void)
{
    Complex c;
    c.a = a;
    c.b = b * -1;
    return c;
}

// Find argument
double Complex::arg(string type)
{
    double rad = atan(std::abs(b / a));
    if (a > 0 && b > 0)
    {
        rad = rad;
    }
    else if (a < 0 && b < 0)
    {
        rad = -(PI - rad);
    }
    else if (a < 0 && b >= 0)
    {
        rad = PI - rad;
    }
    else if (a >= 0 && b < 0)
    {
        rad = -rad;
    }
    if (type == "radians")
    {
        return rad;
    }
    else if (type == "degrees")
    {
        double deg = (rad * 180) / PI;
        return deg;
    }
    return 0;
}
