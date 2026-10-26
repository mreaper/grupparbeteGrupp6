#include "verktyg.h"
#include <string.h>

int hitta_sensor(Sensormatning *sensorregister, int antal, char *namn)
{
    int index = -1;
    for (int i = 0; i < antal; i++)
    {
        if (strcmp(sensorregister[i].namn, namn) == 0)
        {
            index = i;
            break;
        }        
    }
    return index;
}