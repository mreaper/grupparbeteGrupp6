#include <stdio.h>
#include "verktyg.h"

double berakna(double a, double b, char operatortecken)
{
    switch (operatortecken)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        if (b == 0)
            printf("Error: Can't divide by 0.\n");
        else
            return a / b;        
        break;
    default:
        printf("Error: No valid operator.\n");
        break;
    }
    return 0;
}

void byt_plats(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}