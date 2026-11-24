#include <iostream>
#include "verktyg.h"

double berakna(double a, double b, char operatortecken)
{
    switch (operatortecken)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
            std::cout << "Error: Can't divide by 0.\n";
        else
            return a / b;        
        break;
    default:
        std::cout << "Error: No valid operator.\n";
        break;
    }
    return 0;
}

void byt_plats(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}