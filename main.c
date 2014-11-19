#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <getopt.h>
#include "trail.h"
#include "ants.h"
#include "macierz.h"
#include "pheromon.h"
#include "display.h"
#include "prog.h"

int main(int argc, char *argv[] ){



    int mrowki = 0;
    double alpha = 0.0;
    double parowanie = 0.0;
    double beta = 0.0;
    double iloscFeromonu = 0.0;
    int c;
    int maxTime = 0;
    FILE *dist, *read, *fp;
    char *od =NULL;
    char *bu=NULL;
    char *re=NULL;

    while((c = getopt(argc, argv, "m:a:b:p:f:t:d:r:")) != -1)
    {
        switch(c)
        {
            case 'm':
                mrowki = atoi(optarg);
                break;
            case 'a':
                alpha = atof(optarg);
                break;
            case 'b':
                beta= atof(optarg);
                break;
            case 'p':
                parowanie = atof(optarg);
                break;
            case 'f':
                iloscFeromonu=atof(optarg);
                break;
            case 't':
                maxTime = atoi(optarg);
                break;
	    case 'r':
                re = optarg;
                bu = optarg;
                break;
            case 'd':
                od = optarg;
                break;  
            default:
                fprintf(stderr, "Zla opcja \n");
        }
    }
    if( mrowki <1 || alpha < 0.0 || beta < 0.0 || parowanie < 0.0 || iloscFeromonu < 0.0 || maxTime < 1)
	{
		fprintf(stderr, "Musi to być liczba dodatnia\n");
		return EXIT_FAILURE;
	}
    read = fopen (re, "r");
    if (read == NULL)
	{
		fprintf(stderr, "Nie udało się otworzyć pliku: %s \n", re);
		return EXIT_FAILURE;
	}
    fp = fopen (bu, "r");
    if (fp == NULL)
	{
		fprintf(stderr, "Nie udało się otworzyć pliku: %s \n", bu);
		return EXIT_FAILURE;
	}
    dist = fopen (od, "r");
    if (dist == NULL)
	{
		fprintf(stderr, "Nie udało się otworzyć pliku: %s \n", od);
		return EXIT_FAILURE;
	}
	
    int miasta =licz(fp);
    
    srand(time(NULL));
   
    int **graf = stworzGraf(dist,miasta);
    

    char **name = czytajNazwe(read, miasta);
    pokazGraf(graf,name,miasta);

    int **mrow = inicjalizujMrowki(mrowki, miasta); 
    pokazMrowki(mrow, graf, mrowki, miasta);
    
    int *najlepsza = malloc(sizeof(int)*miasta);
    najlepsza = najlepszaSciezka(mrow, graf,miasta,mrowki); 
     
    double najlepszaOdleglosc = Length(najlepsza, graf, miasta); 
    printf("najlepsza %3.2lf\n\n", najlepszaOdleglosc);
   
    double **feromon = inicjalizujFeromon(miasta);
 
    int time = 0;
    while (time < maxTime)
    {
		 
	updateMrowki(mrow, feromon, graf, miasta, mrowki, alpha, beta);
	 updateFeromon(feromon, mrow, graf, parowanie, iloscFeromonu, miasta, mrowki);
      
      	
	  
          int *dotychczasowa_najlepsza_odleglosc = najlepszaSciezka(mrow, graf,miasta,mrowki);
	 
          double doty_najl_odleglosc = Length(dotychczasowa_najlepsza_odleglosc, graf,miasta);
	  
          if (doty_najl_odleglosc < najlepszaOdleglosc)
          {
          	najlepszaOdleglosc = doty_najl_odleglosc;
	       // free(najlepsza);	
          	najlepsza = dotychczasowa_najlepsza_odleglosc;
          	printf("najlepsza odleglosc %3.2lf w czasie %d\n",najlepszaOdleglosc, time);

          }
        time++;
    } 	
	
   	printf("\nNajlepsza sciezka \n");
       DisplayInt(najlepsza, miasta);
    
       free(*feromon);
       free(feromon);
       free(*mrow);
       free(mrow);
       free(*name);
       free(*graf);
       free(name);
       free(graf);
       fclose(read);
       fclose(dist);
    

   return EXIT_SUCCESS;
}
