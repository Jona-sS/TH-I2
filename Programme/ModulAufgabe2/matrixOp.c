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
   cM.spalten = spalten;
   cM.zeilen = zeilen;
   cM.mElement = (MatTyp *)malloc(spalten * zeilen * sizeof(MatTyp));
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
   zM.spalten = spalten;
   zM.zeilen = zeilen;
   zM.mElement = (MatTyp *)malloc(spalten * zeilen * sizeof(MatTyp));
   for (int i = 0; i < zeilen * spalten; i++)
   {
      zM.mElement[i] = 0;
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
   rM.spalten = spalten;
   rM.zeilen = zeilen;
   rM.mElement = (MatTyp *)malloc(spalten * zeilen * sizeof(MatTyp));
   for (int i = 0; i < zeilen * spalten; i++)
   {
      rM.mElement[i] = (rand() % 10) - 5;//anpassbar
   }
   return rM;
}

/*--------------------------------------------------------------------*\
* Kopiert eine Matrix und gibt die Kopie zurueck (yM)
\*--------------------------------------------------------------------*/
Matrix copyMatrix(const Matrix toCopy)
{
   // TODO
   Matrix newM;
   newM.spalten = toCopy.spalten;
   newM.zeilen = toCopy.zeilen;
   for (int i = 0; i < toCopy.spalten * toCopy.zeilen; i++)
   {
      newM.mElement[i] = toCopy.mElement[i];
   }
}

/*--------------------------------------------------------------------*\
* "Loescht" eine Matrix (dM)
* - gibt reservierten Speicher wieder frei !
* - in der urspruenglichen, uebergebenen Matrix bleiben die Werte erhalten!
\*--------------------------------------------------------------------*/
void deleteMatrix(Matrix toDelete)
{
   // TODO
   for (int i = 0; i < toDelete.spalten * toDelete.zeilen; i++)
   {
      free(&toDelete.mElement[i]);
   }
}

/*--------------------------------------------------------------------*\
* "Loescht / Zerstoert" eine uebergegebene Matrix (ddM)
* - gibt Speicher wieder frei, setzt alle Werte auf NULL bzw. "0" !
* - Beachte Unterschiede zur vorigen Funktion !!!
\*--------------------------------------------------------------------*/
void destroyMatrix(Matrix *pToDestroy)
{
   // TODO
   // auf 0 setzen:
   for (int i = 0; i < pToDestroy->zeilen * pToDestroy->spalten; i++)
   {
      pToDestroy->mElement[i] = 0;
   }
   // Speicher frei geben:
   free(pToDestroy->mElement);
}

/*--------------------------------------------------------------------*\
* Gibt den Eintrag der Matrix an der Stelle (xPos, yPos) zurueck (gE)
* Rueckgabe im Fehlerfall: ERROR
\*--------------------------------------------------------------------*/
MatTyp getEntryAt(const Matrix ma, unsigned int xPos, unsigned int yPos)//!Muss auf Call by Reff angepasst werden!
{
   // TODO
   if (xPos > ma.spalten || yPos > ma.zeilen) // Fehler bei Zurgriff außerhalb des Arraybereichs
      return ERROR;
   return ma.mElement[xPos * ma.spalten + yPos];
}

/*--------------------------------------------------------------------*\
* Setzt den Eintrag der Matrix an der Stelle (xPos, yPos) (sE)
* Rueckgabe: TRUE, im Fehlerfall: FALSE
\*--------------------------------------------------------------------*/
Bool setEntryAt(Matrix *ma, unsigned int xPos, unsigned int yPos, MatTyp value)//!Muss auf Call by Reff angepasst werden!
{
   // TODO
   if (xPos > ma->spalten || yPos > ma->zeilen) // Fehler bei Zurgriff außerhalb des Arraybereichs
      return FALSE;
   ma->mElement[xPos * ma->spalten + yPos] = value;
   return TRUE;
}

/*--------------------------------------------------------------------*\
* Gibt eine Matrix im Kommandofenster "schoen formatiert" aus (pM)
\*--------------------------------------------------------------------*/
void printMatrix(const Matrix ma)
{
   // TODO
   int z, s;
   if(ma.spalten==0||ma.zeilen==0){
      printf("Math.ERROR\n");
   }
   for (z = 0; z < ma.zeilen; z++)
   {
      printf("(");
      for (s = 0; s < ma.spalten; s++)
      {
         printf("%8.2f ", ma.mElement[z * ma.spalten + s]);
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
   Matrix aM;
   aM.mElement = (MatTyp *)malloc((ma.spalten * ma.zeilen) * sizeof(MatTyp));
   if (ma.spalten == mb.spalten && ma.zeilen == mb.zeilen)
   { // Addition nur bei gleicher Spalten und Zeilenzahl möglich
      for (int i = 0; i < ma.spalten * ma.zeilen; i++)
      {
         aM.mElement[i] = ma.mElement[i] + mb.mElement[i];
      }
      aM.spalten = ma.spalten;
      aM.zeilen = ma.zeilen;
   }
   else
   {
      aM.spalten = 0;
      aM.zeilen = 0;
   }
   return aM;
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
   Matrix sM;
   sM.mElement = (MatTyp *)malloc((ma.spalten * ma.zeilen) * sizeof(MatTyp));
   if (ma.spalten == mb.spalten && ma.zeilen == mb.spalten)
   { // Subtraktion nur bei gleicher Spalten und Zeilenzahl möglich
      for (int i = 0; i < ma.spalten * ma.zeilen; i++)
      {
         sM.mElement[i] = ma.mElement[i] - mb.mElement[i];
      }
      sM.spalten = ma.spalten;
      sM.zeilen = ma.zeilen;
   }
   else
   {
      sM.spalten = 0;
      sM.zeilen = 0;
   }
   return sM;
}

/*--------------------------------------------------------------------*\
* Multipliziert zwei Matrizen (mM)
* Rueckgabe: "ma * mb"
* - Ergebnis der Multiplikation in neu erzeugter Matrix
* - Rueckgabe im Fehlerfall: Matrix der Groesse "0"
\*--------------------------------------------------------------------*/
Matrix multMatrix(const Matrix ma, const Matrix mb) // testen!
{
   // TODO
   Matrix mM;
   int z, s;
   mM.mElement = (MatTyp *)malloc((mb.spalten * ma.zeilen) * sizeof(MatTyp));
   if (ma.spalten == mb.zeilen)// Multiplikation wenn Spaltenzahl erster gleich der Zeilenzahl der zweiten Matrix
   { 
      // 1. Index der Zielmatrix:
      for (z = 0; z < ma.zeilen; z++)
      {
         for (s = 0; s < mb.spalten; s++)
         {
            mM.mElement[z * mb.spalten + s] = 0;
            // 2. Summe das Produkts von Zeile und Spalte der Multiplikations Matrizen
            for (int i=0; i < ma.spalten; i++)
            {
               mM.mElement[z * mb.spalten + s] += ma.mElement[z * ma.spalten + ( i)] * mb.mElement[( i) * mb.spalten + s];
            //printf("+=%.1f*%.1f\n ",ma.mElement[z * ma.spalten + ( i)],mb.mElement[( i) * mb.spalten + s]);
            }
            //printf("=%.1f\n",mM.mElement[z * mb.spalten + s]);
         }
      }
      mM.spalten = mb.spalten;
      mM.zeilen = ma.zeilen;
   }
   else
   {
      mM.spalten = 0;
      mM.zeilen = 0;
   }
   return mM;
}

/*--------------------------------------------------------------------*\
* Transponiert eine Matrix (tM)
* Rueckgabe: "ma^T"
\*--------------------------------------------------------------------*/
Matrix transposeMatrix(const Matrix ma)
{
   // TODO
   Matrix tM;
   int z, s;
   tM.mElement = (MatTyp *)malloc((ma.spalten * ma.zeilen) * sizeof(MatTyp));
   tM.zeilen = ma.spalten;
   tM.spalten = ma.zeilen;
   for (z = 0; z < ma.zeilen; z++)
   {
      for (s = 0; s < ma.spalten; s++)
      {
         tM.mElement[s * ma.spalten + z] = ma.mElement[z * ma.spalten + s]; // vertauschen der Zeilen und Spalten
      }
   }
   return tM;
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
   double det,produkt;
   int s,z;
   if (ma.spalten != ma.zeilen)
   { // Determinantenberechung nur bei quardratischen Martizen moeglich
      return ERROR;
   }
   //Schraeg runter addieren:
   z=0;//ober Zeile entlang laufen
   for (s = 0; s < ma.spalten; s++)
   {
      produkt=1;
      for (int i = 0; i < ma.spalten; i++)
      {
         produkt*= ma.mElement[(z + i) * ma.spalten + ((s + i)%ma.spalten)];//Problem Ueberlaf da Matrix erweitert werden muss
         //=> wenn s+i=ma.spalten dann soll s+i(wieder)=0 ==>%3 bei 3x3
      }
      det += produkt;
      printf("%.1lf+",produkt);
   }
   printf("=%.1lf\n",det);
   //Schraeg hoch subtrahieren:
   z=ma.zeilen-1;//untere Zeile entlang laufen
   for (s = 0; s < ma.spalten; s++)
   {
      produkt=1;
      for (int i = 0; i < ma.spalten; i++)
      {
         produkt*= ma.mElement[(z - i) * ma.spalten + ((s + i)%ma.spalten)];
      }
      det -= produkt;
      printf("%.1lf-",produkt);
   }
   printf("=%.1lf\n",det);
   return det;
}
