#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include "trail.h"

void DisplayInt(int *sciezka, int rozmiar)
{
	int i;
	for(i=0; i<rozmiar;i++)
	{
		printf("%d ", sciezka[i]+1);
		
			
	}
	printf("\n");
}


void pokazMrowki(int **mrow, int **graf, int mrowki, int miasta)
{	
	int i,j;
	for( i=0; i<mrowki; i++)
	{
		printf("mrowka %d: [ ",i+1);
		for(j=0; j<miasta; j++){
			
			printf("%d ", mrow[i][j]+1);
		}
		printf("] dlugosc = ");
		double len = Length(mrow[i], graf, miasta);
		printf("%3.2lf", len);
		printf("\n");
	}
	
}

void Display(double **feromon, int miasta)
{
	int i,j;
	for(i=0; i< miasta; i++)
	{
		printf(": %d", i);
		for(j=0; j<miasta; j++)
		{
			printf("%lf ", feromon[i][j]);
		}
	printf("\n");
	}
}
  
