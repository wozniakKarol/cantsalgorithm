#include <stdio.h>
#include <stdlib.h>

#include "trail.h"


#ifndef _PHEROMON_H_
#define _PHEROMON_H_

double **inicjalizujFeromon(int miasta);
void updateFeromon(double **feromon, int **mrow, int **graf, double parowanie, double iloscFeromonu, int miasta, int mrowki);

#endif
