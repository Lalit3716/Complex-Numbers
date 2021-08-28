#include <string>
#include <regex>
#include "complex.h"
#include "calculator.h"
#include "utils.h"

// Driver Code
int main()
{
    int n;
    string s;
    system("Color 00");
    cout << "\033[1;34m--> Enter how many complex numbers you want to work with: ";
    cin >> n;
    while (!n)
    {
        cout << "--> Please give a valid integer: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> n;
    }
    Complex complexes[n];
    for (int i = 0; i < n; i++)
    {
        float a, b;
        cout << "--> " << i + 1 << ". ";
        cout << "Give Space Seprated Values for a+bj: ";
        while (!(cin >> a >> b))
        {
            cout << "\033[1;031m";
            cout << "--> ";
            cout << "Please give valid integers/floats: ";
            cout << "\033[1;34m";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        Complex c(a, b);
        complexes[i] = c;
    }
    cout << endl;
    cout << "\033[1;31m*********************************************************\033[0m" << endl;
    cout << endl;
    instructions();
    while (true)
    {
        Calc Calculator;
        smatch sm;
        cout << "\033[1;31m" << endl;
        cout << "--> ";
        getline(cin, s);
        if (s == "q" || s == "quit")
        {
            break;
        }
        if (s == "print")
        {
            print_all(complexes, n);
        }
        else if (regex_search(s, sm, regex("print (\\d+)")))
        {
            int i = stoi(sm[1]) - 1;
            print_by_i(complexes, i, n);
        }
        else if (regex_search(s, sm, regex("(\\d+)([+\\-\\*])(\\d+)")))
        {
            int i = stoi(sm[1]) - 1;
            string m = sm[2];
            int j = stoi(sm[3]) - 1;
            if (i >= n || j >= n)
            {
                cout << "Invalid Indices" << endl;
            }
            else
            {
                Complex arr[2] = {complexes[i], complexes[j]};
                cout << "\033[1;36m";
                Calculator.calculate(arr, 2, m).print();
            }
        }
        else if (s == "add" || s == "sub" || s == "mul")
        {
            cout << "\033[1;36m";
            Calculator.calculate(complexes, n, s).print();
        }
        else if (regex_search(s, sm, regex("conjugate (\\d+)")))
        {
            int i = stoi(sm[1]) - 1;
            if (i >= n)
            {
                cout << "Invaild Index" << endl;
            }
            else
            {
                cout << "\033[1;36m";
                complexes[i].conjugate().print();
            }
        }
        else if (regex_search(s, sm, regex("arg\\((\\d+)\\)")))
        {
            int i = stoi(sm[1]) - 1;
            if (i >= n)
            {
                cout << "Invalid Index" << endl;
            }
            else
            {
                double rads = complexes[i].arg("radians");
                double deg = (rads * 180) / PI;
                cout << "\033[1;36m";
                cout << "arg in radians: " << rads << endl;
                cout << "arg in degree: " << deg << endl;
            }
        }
        else if (s == "conjugate")
        {
            cout << "\033[1;36m";
            print_conjugates(complexes, n);
        }
        else if (s == "args")
        {
            cout << "\033[1;36m";
            print_args(complexes, n);
        }
        else
        {
            cout << "Please Type a valid Command Only" << endl;
        }
        cout << "_________________________________________________________________" << endl;
    }
}