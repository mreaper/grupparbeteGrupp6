#include "verktyg.h"
#include <stdlib.h>
#include <stdio.h>

double *lagg_till_matning(double *logg, int *antal, double varde)
{
	double *ny_logg;

	if (logg == NULL)
	{
		ny_logg = malloc(sizeof(double));
	}
	else
	{
		ny_logg = realloc(logg, (*antal + 1) * sizeof(double));
	}

	if (ny_logg != NULL)
	{
		ny_logg[*antal] = varde;
		(*antal)++;
		return ny_logg;
	}

	else{printf("malloc or realloc failed"); return logg;}

}
