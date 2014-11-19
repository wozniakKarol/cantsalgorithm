#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trail.h"
#include <assert.h>
#include "prog.h"



int Index( int *sciezka, int cel, int size)
{
   
         
	int i;
	int j;
	for ( i =0; i < size; i++)
	{
		if ( sciezka[i] == cel)
		{
			j= i;

		}
		
			
	}
        assert(j>=0.);
	return j;
	
}

double odleglosc( int miastoA, int miastoB, int **graf)
{       
        //assert(miastoB>=0 && miastoB <22);
	return graf[miastoA][miastoB];
}

double Length( int *sciezka, int **graf, int size)
{
	double wynik =0.0;
	int i;
	for(i=0; i< size -1; i++)
		wynik += odleglosc(sciezka[i], sciezka[i+1], graf);
	return wynik;
}


int random_number(int min_num, int max_num)
{
	int result=0;
    if(min_num<max_num)
	{
    	 result = (rand()%(max_num- min_num)) + min_num;
	}
    else {
	int tmp;
	tmp = max_num;
	max_num = min_num;
	min_num = tmp;
	result = (rand()%(max_num- min_num)) + min_num;
	}
    return result;


}


double randomDouble(double min, double max) 
{
	double range = (max - min); 
	double div = RAND_MAX / range;

	return min + (rand() / div);
}

 double randomDoub()
{
	
	return ((double)rand()/(double)RAND_MAX);

}


void copyTo( int *source, int size, int *target)
{
	int i;
	
	for(i=0; i< size  ; i++)
	{ 
	     target[i]=source[i];
	}

}


 int *najlepszaSciezka( int **mrow, int **graf, int miasta, int mrowki)
{
	double najlepszaDlugosc = Length(mrow[0], graf, miasta);
	
	int j =0;
	int i;
	int *najlepsza = calloc(miasta,sizeof(int));
	for ( i=1; i < mrowki; i++)
	{
		double len = Length(mrow[i], graf,miasta);
		if ( len < najlepszaDlugosc)
		{
			najlepszaDlugosc = len;
			j = i;
		}
		
		
		
	}
	copyTo(mrow[j], miasta,najlepsza);
	
	return najlepsza;
}



int *losowaSciezka( int start, int miasta)
{
	int *sciezka = calloc(miasta,sizeof(int));
	int i;
	for(i=0; i< miasta; i++)
            sciezka[i]=i;
	for(i=0; i< miasta; i++)
	{
		int r = random_number(i, miasta);
               // printf("%d ", r);
		int tmp = sciezka[r];
               // printf("tmp %d ", tmp);
		sciezka[r]=sciezka[i];
		sciezka[i]=tmp;
        
                //printf("sciez %d ", sciezka[i]);
	}
	int id = Index(sciezka,start,miasta);
	int temp =sciezka[0];
	sciezka[0]=sciezka[id];
	sciezka[id]=temp;
	
	return sciezka;
}

int *budujSciezka(int k, int start, double **feromon, int **graf, int miasta, double alpha, double beta)
{
	
       	int *trasa = malloc((miasta)*sizeof(int));
	bool odwiedzone[miasta];
	int i;
	trasa[0] = start;
	
	odwiedzone[0] = true;
	
	for(i=0; i < miasta-1; i++)
	{
		int miastoA = trasa[i];
		
            
		
		int next = nastepneMiasto(k, miastoA, odwiedzone, feromon, graf ,miasta, alpha, beta);
	
		trasa[i+1] = next;
		odwiedzone[next]=true;
            
	}
       
	return trasa;
}



bool krawedzW_sciezce( int miastoA, int miastoB, int *sciezka, int miasta)
{
/*	int lastIndex = miasta-1;
	
	
	int id = Index(sciezka, miastoA, miasta);
//        printf("%d ", id);
        
	bool t;
	if (id == 0 && sciezka[1] == miastoB)
                         t = true;
        else if (id == 0 && sciezka[lastIndex] == miastoB)
                         t = true;
	else if (id == 0)
                         t = false;
	else if (id == lastIndex && sciezka[lastIndex - 1] == miastoB)
                         t = true;
	else if (id == lastIndex && sciezka[0] == miastoB)
                         t = true;
	else if (id == lastIndex)
                         t = false;
	else if ( sciezka[id - 1] == miastoB)
                         t = true;
	else if (sciezka[id + 1] == miastoB)
                         t = true;
	else
            t = false;
       */
         int i;
         bool t;
        for(i=1; i<miasta -1; i++)
        {
            assert(i<miasta-1 && i>0);
            if((sciezka[i-1] == miastoA && sciezka[i]==miastoB) || (sciezka[i]==miastoA && sciezka[i+1]==miastoB))
                t= true;
            else
                t= false;
        }
return t;
}
