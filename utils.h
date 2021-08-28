#pragma once
#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;

void instructions(void)
{
    cout << "\033[1;34m-> Type q/quit to exit the program\033[m" << endl;
    cout << "\033[1;34m-> Type print to print all\033[m" << endl;
    cout << "\033[1;34m-> Type print i to print ith number\033[m" << endl;
    cout << "\033[1;34m-> Type add to add all\033[m" << endl;
    cout << "\033[1;34m-> Type sub to subtact all\033[m" << endl;
    cout << "\033[1;34m-> Type mul to multiply all\033[m" << endl;
    cout << "\033[1;34m-> Type conjugate to see conjugates of all\033[m" << endl;
    cout << "\033[1;34m-> Type args to see arguments of all complex numbers\033[m" << endl;
    cout << "\033[1;34m-> Type i(+/-/*)j to perform respective operation on i, j\033[m" << endl;
    cout << "\033[1;34m-> Type conjugate i to see conjugate of ith number\033[m" << endl;
    cout << "\033[1;34m-> Type arg(i) to print argument of ith number\033[m";
}

void print_all(Complex arr[], int n)
{
    cout << "\033[1;36m";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". ";
        arr[i].print();
    }
}

void print_by_i(Complex arr[], int i, int n)
{
    cout << "\033[1;36m";
    if (i < n)
    {
        arr[i].print();
    }
    else
    {
        cout << "You have given only " << n << " Numbers" << endl;
    }
}

void print_conjugates(Complex arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". ";
        arr[i].conjugate().print();
    }
}

void print_args(Complex arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". ";
        cout << "Radians: " << arr[i].arg("radians") << endl;
        cout << "Degrees: " << arr[i].arg("degrees") << endl;
        cout << "_________________________________________________________________" << endl;
    }
}