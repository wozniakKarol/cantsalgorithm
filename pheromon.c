#include <stdio.h>
#include <stdlib.h>
#include "pheromon.h"
#include "trail.h"


double **inicjalizujFeromon(int miasta)
{
	double **feromon;
	int i;
	
        feromon=malloc(sizeof(double *)*miasta);
        for(i=0; i<miasta; i++)
        {
            feromon[i]=malloc(sizeof(double)*miasta);
        }
	int j;
	for(i=0; i< miasta; i++)
	{
		for(j=0; j< miasta; j++)
			feromon[i][j]=0.1;
	}
return feromon;
}


void updateFeromon(double **feromon, int **mrow, int **graf, double parowanie, double iloscFeromonu, int miasta, int mrowki)
{
	int i,j,k;
	for(i=0; i < miasta; i++)
	{
		for( j=i+1; j < miasta; j++)
		{
			for(k=0; k < mrowki; k++)
			{
				double length = Length(mrow[k], graf, miasta);
				
				double decrease = (1.0 -parowanie) * feromon[i][j];
				double increase = 0.0;
				
				if( krawedzW_sciezce(i,j,mrow[k], miasta) == true){
					increase = (iloscFeromonu/length);
                                }
				feromon[i][j] = decrease + increase;
				
				if(feromon[i][j] < 0.001)
					feromon[i][j] =0.01;
				else if(feromon[i][j] > 100000.0)
					feromon[i][j] = 100000.0;

				feromon[j][i] = feromon[i][j];
				
			}
		}
	}
} 

