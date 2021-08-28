#pragma once
#include "complex.h"
class Calc
{
public:
    Complex add(Complex, Complex);

    Complex subtract(Complex, Complex);

    Complex multiply(Complex, Complex);

    Complex calculate(Complex arr[], int n, string method);
};

Complex Calc::add(Complex c1, Complex c2)
{
    Complex c;
    c.a = c1.a + c2.a;
    c.b = c1.b + c2.b;
    return c;
}
Complex Calc::subtract(Complex c1, Complex c2)
{
    Complex c;
    c.a = c1.a - c2.a;
    c.b = c1.b - c2.b;
    return c;
}
Complex Calc::multiply(Complex c1, Complex c2)
{
    Complex c;
    float real, imag;

    real = c1.a * c2.a + c1.b * c2.b * -1;
    imag = c1.a * c2.b + c1.b * c2.a;
    c.a = real;
    c.b = imag;
    return c;
}
Complex Calc::calculate(Complex arr[], int n, string method)
{
    Complex c;
    c.setNumber(arr[0].a, arr[0].b);
    for (int i = 1; i < n; i++)
    {
        if (method == "add" || method == "+")
        {
            c = add(c, arr[i]);
        }
        else if (method == "sub" || method == "-")
        {
            c = subtract(c, arr[i]);
        }
        else if (method == "mul" || method == "*")
        {
            c = multiply(c, arr[i]);
        }
    }
    return c;
}