#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ants.h"
#include "trail.h"



int **inicjalizujMrowki( int mrowki, int miasta)
{
    
    int j;
  
    int* sciezka = calloc(miasta*mrowki, sizeof(int));
    int** mrow = malloc(mrowki*sizeof(int*));
    for(j=0; j<mrowki;j++)
    {
        int start =0;
        sciezka = losowaSciezka(start, miasta);
        mrow[j] = sciezka;
	
    }
    return mrow;
}



void updateMrowki( int **mrow, double **feromon, int **graf, int miasta, int mrowki, double alpha, double beta)
{

    int k;
    for( k=0; k < mrowki; k++)
    {
        int start =0;
	
        
        int *nowaSciezka = malloc(miasta*sizeof(int));
        nowaSciezka = budujSciezka(k, start, feromon, graf, miasta, alpha, beta);
        
          
            mrow[k] = nowaSciezka;
        
    }
}


