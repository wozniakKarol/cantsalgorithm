 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "macierz.h"   
int **stworzGraf(FILE *file, int miasta)
    {
        int i;
        int j;
     
     
     
        int **mat;
       
     	
      
	mat = calloc(miasta, sizeof(int*));
	for(i=0; i<miasta; i++)
		{
			mat[i]= calloc(miasta, sizeof(int));
		}
	if(!mat)
	{
		printf("Blad alokacji pamieci\n");
                exit(1);
	}
     
     
        for(i = 0; i < miasta; i++)
        {
            for(j = 0; j <miasta; j++)
            {
     
                if (!fscanf(file, "%d", &mat[i][j]))
                    break;
               
            }
         
     
        }
     
        return mat;
    }
     
  char **czytajNazwe(FILE *file, int miasta)
    {
        int i;
        char **name = malloc(miasta*sizeof(char*));
        int j;
        for(j=0; j<miasta;j++)
            name[j] = malloc((miasta+1)*sizeof(char));
     
        
     
        for(i=0; i<miasta; i++)
        {
     
     
                if(!fscanf(file, "%s", name[i]))
                    break;
               
           
        }
     
        return name;
    }
void pokazGraf(int **graf, char **name, int miasta)
    {
        int i,j, k;
        printf("\t\t");
        for(i=0; i<miasta; i++)
        {
            for(j=0; j<miasta; j++)
            {
                printf("%c", name[i][j]);
     
            }
            printf(" ");
     
        }
        printf("\n");
        for(i=0; i<miasta; i++)
        {
     
                printf("%10s", name[i]);
           
            printf("\t");
            for(k=0; k<miasta; k++)
            {
                printf("%5d", graf[i][k]);
            }
            printf("\n");
        }
     
    }
     

int licz(FILE *fp)
	{
	
    	int c;             
    	int newline_count = 0;

        
   	 while ( (c=fgetc(fp)) != EOF ) {
        	if ( c == '\n' )
           	 newline_count++;
    		}

    
    	return newline_count;
	}

