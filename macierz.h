#include <stdio.h>
#include <stdlib.h>

#ifndef _MACIERZ_H_
#define _MACIERZ_H_

int **stworzGraf(FILE *file, int miasta);
char **czytajNazwe(FILE *file, int miasta);
void pokazGraf(int **graf, char **name, int miasta);
int licz(FILE *fp);

#endif
