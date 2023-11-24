/**********************************************************************\
* Kurzbeschreibung:
* "Funktionstest" - Matrizen mit Werten erzeugen
* und alle implementierten Funktionen aus matrixOp.c zum Test aufrufen
* 
* Datum:     Autor:
* 
*
\**********************************************************************/

/*--- #includes ------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS //VC++: keine scanf() Warnungen
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrixOp.h"

/*--- #defines -------------------------------------------------------*/

/*--- Lokale Datentypen (typedef) ------------------------------------*/

/*--- Modulglobale static Variablen ----------------------------------*/

/*--- Prototypen lokaler Funktionen ----------------------------------*/

/*--- Funktionsdefinitionen ------------------------------------------*/

/*--- main -----------------------------------------------------------*/
int main(void) 
{
   // TODO
   int zeilen,spalten;
   char komma;
   Matrix zM,rM;
   printf(" Zeilen, Spalten (> 0; z.B.: 3,4): ");
   while (scanf("%d%c%d",&zeilen,&komma,&spalten)!=3||zeilen<=0||spalten<=0||komma!=',')
   {
      printf("falsche Eingabe, erneut: ");
      while(getchar()!='\n');
   }
   printf("Nullmatrix test:\n");
   zM=createMatrixZero(spalten,zeilen);
   printMatrix(zM);
   printf("Zufallmatrix test:\n");
   rM=createMatrixRand(spalten,zeilen);
   printMatrix(rM);
}
