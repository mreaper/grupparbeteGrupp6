#include "verktyg.h"
#include <stdio.h>

void skriv_matlogg(double *logg, int antal)
{
    if (antal < 1)
    {
        printf("Matloggen ar tom.\n");
        return;
    }
    
    printf("Matlogg:\n");
    for (int i = 0; i < antal; i++)
    {
        printf("%d: %2.f\n", antal, logg[i]);
    }
}