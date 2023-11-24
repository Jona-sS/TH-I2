/**********************************************************************\
* Kurzbeschreibung: matrixOp.c
* Bietet Funktionen fuer Operationen mit Matrizen
*
* Datum:       Autor:        Grund der Aenderung:
* 
*
\**********************************************************************/

/*--- #includes ------------------------------------------------------*/
#include <float.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrixOp.h"

/*--- #defines -------------------------------------------------------*/

/*--- Lokale Datentypen (typedef) ------------------------------------*/

/*--- Modulglobale static Variablen ----------------------------------*/

/*--- Prototypen lokaler Funktionen ----------------------------------*/

/*--- Funktionsdefinitionen ------------------------------------------*/

/*--------------------------------------------------------------------*\ 
* Erstellt eine neue Matrix (cM)
*  - reserviert lediglich den notwendigen Speicher
*  - dynamische Verwaltung von Speicher muss mit malloc() und free() 
*    durchgef�hrt werden; dynamische Arrays sind nicht erlaubt !!!
\*--------------------------------------------------------------------*/
Matrix createMatrix(unsigned int spalten, unsigned int zeilen) 
{
   // TODO
   Matrix cM;
   cM.spalten=spalten;
   cM.zeilen=zeilen;
   cM.mElement= (MatTyp*)malloc(spalten*zeilen*sizeof(MatTyp));
   return cM;
}

/*--------------------------------------------------------------------*\
* Erstellt und initialisiert eine neue Matrix (zM)
* - reserviert den notwendigen Speicher
* - befuellt die Matrix mit 0
\*--------------------------------------------------------------------*/
Matrix createMatrixZero(unsigned int spalten, unsigned int zeilen) 
{
   // TODO
   Matrix zM;
   zM.spalten=spalten;
   zM.zeilen=zeilen;
   zM.mElement= (MatTyp*)malloc(spalten*zeilen*sizeof(MatTyp));
   for (int i=0; i < zeilen*spalten; i++) {
      zM.mElement[i] = 1;//test
      printf("%d",zM.mElement[i]);
   }
   
   return zM;
}

/*--------------------------------------------------------------------*\
* Erstellt und initialisiert eine neue Matrix (rM)
* - reserviert den notwendigen Speicher
* - befuellt die Matrix mit Zufallszahlen (-100 bis +100)
\*--------------------------------------------------------------------*/
Matrix createMatrixRand(unsigned int spalten, unsigned int zeilen) 
{
   // TODO        ->wie createZeroMatrix nur mit rand
   srand(time(NULL));
   Matrix rM;
   rM.spalten=spalten;
   rM.zeilen=zeilen;
   rM.mElement= (MatTyp*)malloc(spalten*zeilen*sizeof(MatTyp));
   for (int i=0; i < zeilen*spalten; i++) {
      rM.mElement[i] = rand()%200-100;
   }
   return rM;
}

/*--------------------------------------------------------------------*\
* Kopiert eine Matrix und gibt die Kopie zurueck (yM)
\*--------------------------------------------------------------------*/
Matrix copyMatrix(const Matrix toCopy) 
{
   // TODO
}

/*--------------------------------------------------------------------*\
* "Loescht" eine Matrix (dM)
* - gibt reservierten Speicher wieder frei !
* - in der urspruenglichen, uebergebenen Matrix bleiben die Werte erhalten!
\*--------------------------------------------------------------------*/
void deleteMatrix(Matrix toDelete) 
{
   // TODO
}

/*--------------------------------------------------------------------*\
* "Loescht / Zerstoert" eine uebergegebene Matrix (ddM)
* - gibt Speicher wieder frei, setzt alle Werte auf NULL bzw. "0" !
* - Beachte Unterschiede zur vorigen Funktion !!! 
\*--------------------------------------------------------------------*/
void destroyMatrix(Matrix *pToDestroy) 
{
   // TODO
}

/*--------------------------------------------------------------------*\
* Gibt den Eintrag der Matrix an der Stelle (xPos, yPos) zurueck (gE)
* Rueckgabe im Fehlerfall: ERROR
\*--------------------------------------------------------------------*/
MatTyp getEntryAt(const Matrix ma, unsigned int xPos, unsigned int yPos) 
{
   // TODO
}

/*--------------------------------------------------------------------*\
* Setzt den Eintrag der Matrix an der Stelle (xPos, yPos) (sE)
* Rueckgabe: TRUE, im Fehlerfall: FALSE
\*--------------------------------------------------------------------*/
Bool setEntryAt(Matrix ma, unsigned int xPos, unsigned int yPos, MatTyp value) 
{
   // TODO
}

/*--------------------------------------------------------------------*\
* Gibt eine Matrix im Kommandofenster "schoen formatiert" aus (pM)
\*--------------------------------------------------------------------*/
void printMatrix(const Matrix ma) 
{
   // TODO
   int z,s;
   for (z=0; z < ma.zeilen; z++) {
      printf("(");
      for (s=0; s < ma.spalten; s++) {
         printf("%6.4d ", ma.mElement[z*ma.spalten + s]);
      }
      printf(")\n");
   }
}

/*--------------------------------------------------------------------*\
* Addiert zwei Matrizen (aM)
* Rueckgabe:
* - Ergebnis der Addition in neu erzeugter Matrix
* - Rueckgabe im Fehlerfall: Matrix der Groesse "0"
\*--------------------------------------------------------------------*/
Matrix addMatrix(const Matrix ma, const Matrix mb) 
{
   // TODO
}

/*--------------------------------------------------------------------*\
* Subtrahiert zwei Matrizen (sM)
* Rueckgabe: "ma - mb"
* - Ergebnis der Subtraktion in neu erzeugter Matrix
* - Rueckgabe im Fehlerfall: Matrix der Groesse "0"
\*--------------------------------------------------------------------*/
Matrix subMatrix(const Matrix ma, const Matrix mb) 
{
   // TODO
}

/*--------------------------------------------------------------------*\
* Multipliziert zwei Matrizen (mM)
* Rueckgabe: "ma * mb"
* - Ergebnis der Multiplikation in neu erzeugter Matrix
* - Rueckgabe im Fehlerfall: Matrix der Groesse "0"
\*--------------------------------------------------------------------*/
Matrix multMatrix(const Matrix ma, const Matrix mb) 
{
   // TODO
}

/*--------------------------------------------------------------------*\
* Transponiert eine Matrix (tM)
* Rueckgabe: "ma^T"
\*--------------------------------------------------------------------*/
Matrix transposeMatrix(const Matrix ma) 
{
   // TODO
}

/*--------------------------------------------------------------------*\
* Gibt die Determinante der Matrix ma zurueck (dt)
* Rueckgabe im Fehlerfall: ERROR
* !!! Optional / Implementation freiwillig !!!
* fuer kleine Matrizen reicht ein einfacher Algorithmus
* wer moechte kann auch ein effizientes Verfahren implementieren
\*--------------------------------------------------------------------*/
double determMatrix(const Matrix ma) 
{
   // TODO
}

