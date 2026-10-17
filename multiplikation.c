#include "verktyg.h"
#include <stdio.h>

void skriv_multiplikationstabell(int tal)
{
	for (int i = 1; i <= 10; i++)
	{
		printf("%d * %d = ", tal, i);
		int res = tal * i;
		printf("%d\n", res);

	}
}


void skriv_flera_tabeller(int tal[], int antal)
{
	for (int i = 0; i < antal; i++)
	{
		skriv_multiplikationstabell(tal[i]);
	}
}
