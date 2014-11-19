#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define DBL_MAX 1000000000000000 
#include "prog.h"
#include "trail.h"
#include <assert.h>

double *prawdopodobienstwo(int k, int miastoA, bool *odwiedzone, double **feromon, int **graf, int miasta, double alpha, double beta)
{
	
	double tau[miasta];
	double sum = 0.0;
	int i;
	int j=0;

	for(i =0; i< miasta; i++)
	{	tau[i]=0.0;
		
		if(i!=miastoA && odwiedzone[i]!=true)
		{
		
		tau[i]	= pow(feromon[miastoA][i], alpha) * pow((1.0/odleglosc(miastoA,i,graf)),beta);
		
   		 sum +=tau[i];	
		j++;
		}	
		
             
	}
	
        double ha=0.0;
	double *prop = malloc(miasta*sizeof(double));
	for(i=0; i<miasta; i++){
		prop[i] = tau[i] /sum;	
                ha += prop[i];
                
		}
	// printf("ha %lf\n", ha);
	//assert(ha==1.);
	return prop;
}

int nastepneMiasto( int k, int miastoA, bool *odwiedzone, double **feromon, int **graf, int miasta, double alpha, double beta)
{	
   	
	double *prop = malloc(miasta*sizeof(double));
	prop = prawdopodobienstwo(k, miastoA, odwiedzone, feromon, graf,miasta, alpha, beta);
	
	double a[miasta+1];
	int i;
	a[0]=0.0;
	for(i=0; i < miasta; i++){
		a[i+1] = a[i] + prop[i];
        }
		
	double p = randomDoub();
	
	int j=0;
	for(i=0; i <  miasta ; i++){
		if( p >= a[i] && p < a[i+1]){
			
			j=i;
			break;
                }
		
                }
                
	return j;
    

}




