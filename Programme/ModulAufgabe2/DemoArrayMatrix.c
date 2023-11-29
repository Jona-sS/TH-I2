/**********************************************************************\
* Kurzbeschreibung:
* Demo-Programm - Zugriff auf Array vs. Matrix 
* 
* Datum:     Autor:
* 01.10.2015  Dr. Bruno Lurz
*
\**********************************************************************/

/*--- #includes ------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

#define SPAL 5
#define ZEIL 4


/*--- main -----------------------------------------------------------*/
int main(void) {
   int array[ZEIL*SPAL];
   int array2[ZEIL*SPAL];
   int matrix[ZEIL][SPAL];
   int i, s, z;

   for (i=0; i < ZEIL*SPAL; i++) {
      array[i] = i;
   }
   
   for (z=0, i=0; z < ZEIL; z++) {
      for (s=0; s < SPAL; s++, i++) {
         matrix[z][s] = array[i];
      }
   }
   
   for (z=0, i=0; z < ZEIL; z++) {
      for (s=0; s < SPAL; s++, i++) {
         array2[z*SPAL + s] = array[i];//1D Array wie 2D befuellen
      }
   }
   
   
   printf("\n matrix =\n");
   for (z=0; z < ZEIL; z++) {
      printf("(");
      for (s=0; s < SPAL; s++) {
         printf("%6.4d ", matrix[z][s]);
      }
      printf(")\n");
   }
   
   printf("\n array2 =\n");
   for (z=0; z < ZEIL; z++) {
      printf("(");
      for (s=0; s < SPAL; s++) {
         printf("%6.4d ", array2[z*SPAL + s]);
      }
      printf(")\n");
   }
   
   return 0;
}
