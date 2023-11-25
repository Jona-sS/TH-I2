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
void eingabeGroesse(int *zeilen, int *spalten){
   char komma;
   printf(" Zeilen, Spalten (> 0; z.B.: 3,4): ");
   while (scanf("%d%c%d",zeilen,&komma,spalten)!=3||zeilen<=0||spalten<=0||komma!=',')
   {
      printf("falsche Eingabe, erneut: ");
      while(getchar()!='\n');
   }
}
/*--- main -----------------------------------------------------------*/
int main(void) 
{
   // TODO
   Matrix rMa,rMb,addM,mulM;
   int zeilen,spalten;
   //1. zufällige Matrix erstellen
   eingabeGroesse(&zeilen,&spalten);
   printf("1. Zufallmatrix(a):\n");
   rMa=createMatrixRand(spalten,zeilen);
   printMatrix(rMa);
   //2. zufällige Matrix erstellen
   eingabeGroesse(&zeilen,&spalten);
   printf("2. Zufallmatrix(b):\n");
   rMb=createMatrixRand(spalten,zeilen);
   printMatrix(rMb);
   //Matrizzen addieren:
   printf("\na+b=\n");
   addM=addMatrix(rMa,rMb);
   printMatrix(addM);
   //einen Wert Setzen:
   printf("Setze Wert(in b):\n");
   setEntryAt(&rMb,1,1,99);
   printMatrix(rMb);
   //Matrizze loeschen und auf Null:
   printf("Delet and Zero(Additionsergebis):\n");
   destroyMatrix(&addM);
   printMatrix(addM);
   printf("a*b:\n");
   //Matrizzen Multiplizieren:
   mulM=multMatrix(rMa,rMb);
   printMatrix(mulM);
   //Matrizze transponieren:
   printf("Transponierte(Multiplikationsergebnis):\n");
   mulM=transposeMatrix(mulM);
   printMatrix(mulM);
   //Determinante berechnen:
   printf("Determinante(von a): %.2lf",determMatrix(rMa));
}