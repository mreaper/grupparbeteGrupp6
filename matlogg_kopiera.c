#include "verktyg.h"
#include <stdlib.h>

double* kopiera_matlogg(double *logg, int antal)
{
    if (antal < 1)
        return NULL;

    double *kopia = malloc(sizeof(double) * antal);

    for (int i = 0; i < antal; i++)
        kopia[i] = logg[i];
        
    return kopia;
}