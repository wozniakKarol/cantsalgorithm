#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "prog.h"
#ifndef _TRAIL_H_
#define _TRAIL_H_

int Index( int *sciezka, int cel, int size);
double odleglosc( int miastoA, int miastoB, int **graf);
double Length( int *sciezka, int **graf, int size);
int random_number(int min_num, int max_num);
double randomDouble(double min, double max);
double randomDoub();
void copyTo( int *source, int size, int *target);
int *najlepszaSciezka( int **mrow, int **graf, int miasta, int mrowki);
int *losowaSciezka( int start, int miasta);
int *budujSciezka(int k, int start, double **feromon, int **graf, int miasta, double alpha, double beta);
bool krawedzW_sciezce( int miastoA, int miastoB, int *sciezka, int miasta);




#endif
