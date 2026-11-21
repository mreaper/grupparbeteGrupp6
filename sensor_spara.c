#include "verktyg.h"
#include <stdio.h>
#include <stdlib.h>

void spara_sensorregister(char *filnamn, Sensormatning *sensorregister, int antal)
{
    FILE *fil = fopen(filnamn, "w");
    if (fil == NULL)
    {
        printf("Error: could not open file.");
        return;
    }

    for (int i = 0; i < antal; i++)
    {
        fprintf(fil, "%s %.2f\n");
    }
    fclose(fil);
}