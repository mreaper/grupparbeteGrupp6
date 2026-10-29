#include <stdlib.h>
#include <string.h>
#include "verktyg.h"
#include <stdio.h>

Sensormatning *lagg_till_sensormatning(Sensormatning *reg, int *antal,
		const char *namn, double varde)
{
	Sensormatning *ny_reg;

	if (reg == NULL){ny_reg = malloc(sizeof(Sensormatning));}
	else {ny_reg = realloc(reg, (*antal + 1) * sizeof(Sensormatning));}

	if (ny_reg == NULL){printf("Kunde inte allokera minne for sensorregistret.\n"); return reg;}
	else
	{
		strncpy(ny_reg[*antal].namn, namn, 50);
		ny_reg[*antal].namn[49] = '\0';
		ny_reg[*antal].varde = varde;
		(*antal)++;
		
		return ny_reg;
	}


}
	
