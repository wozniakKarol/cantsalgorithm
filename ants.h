#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "trail.h"

#ifndef _ANTS_H_
#define _ANTS_H_

int ** inicjalizujMrowki( int mrowki, int miasta);
void updateMrowki( int ** mrow, double ** feromon, int ** graf, int miasta, int mrowki, double alpha, double beta);

#endif
