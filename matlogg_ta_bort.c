#include "verktyg.h"
#include <stdio.h>
#include <stdlib.h>


double *ta_bort_senaste_matning(double *logg, int *antal)
{
	if (logg != NULL)
	{
		if (*antal == 1)
		{
			free(logg);
			*antal = 0;
			return NULL;
		}
		
		else
		{
			double *ny_logg;
			ny_logg = realloc(logg, (*antal - 1) * sizeof(double));
			
			if (ny_logg == NULL){printf("realloc failed\n"); return logg;}
			else
			{
				(*antal)--;
				return ny_logg;
			}
		}
	}
	else
		return NULL;
}
