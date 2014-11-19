#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <math.h>


#ifndef _PROG_H_
#define _PROG_H_

double *prawdopodobienstwo(int k, int miastoA, bool *odwiedzone, double **feromon, int **graf, int miasta, double alpha, double beta);

int nastepneMiasto( int k, int miastoA, bool *odwiedzone, double **feromon, int **graf, int miasta, double alpha, double beta);

#endif
