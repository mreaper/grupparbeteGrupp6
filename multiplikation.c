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
