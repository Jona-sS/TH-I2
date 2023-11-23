/**********************************************************************\
* Kurzbeschreibung:
* "Funktionstest" - 2 komplexe Zahlen einlesen
* und alle implementierten Funktionen aus complex.c zum Test aufrufen
*
* Datum:     Autor:
*
*
\**********************************************************************/

/*--- #includes ------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS // VC++: keine scanf() Warnungen
#include <stdio.h>
#include "complex.h"

/*--- #defines -------------------------------------------------------*/

/*--- Lokale Datentypen (typedef) ------------------------------------*/

/*--- Modulglobale static Variablen ----------------------------------*/

/*--- Prototypen lokaler Funktionen ----------------------------------*/
Complex eingabe(int zahlNummer);
/*--- Funktionsdefinitionen ------------------------------------------*/
Complex eingabe(int zahlNummer)
{
   Complex e;
   printf("%d.Zahl eingeben\n        Realteil: ", zahlNummer);
   while (scanf("%lf", &e.real) != 1)
   {
      printf("gib eine Zahl ein: ");
      while (getchar() != '\n');
   }
   printf(" Imaginaeranteil: ");
   while (scanf("%lf", &e.imag) != 1)
   {
      printf("gib eine Zahl ein: ");
      while (getchar() != '\n');
   }
   return e;
}
/*--- main -----------------------------------------------------------*/
int main(void)
{
   // TODO
   Complex x, y;
   // Eingabe
   x = eingabe(1);
   y = eingabe(2);
   // Augabe der Eingegbenen Zahlen
   printf("\nx = ");
   printComplex(x);
   printf("\ny = ");
   printComplex(y);
   // Ausgabe und Berechnung
   printf("\n\nSumme: \t\tx + y = ");
   printComplex(addComplex(x, y));
   printf("\nDifferenz: \tx - y = ");
   printComplex(subComplex(x, y));
   printf("\nProdukt: \tx * y = ");
   printComplex(mulComplex(x, y));
   printf("\nQuotient: \tx / y = ");
   printComplex(divComplex(x, y));
}