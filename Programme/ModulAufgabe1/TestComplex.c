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
#define _CRT_SECURE_NO_WARNINGS //VC++: keine scanf() Warnungen
#include <stdio.h>
#include "complex.h"

/*--- #defines -------------------------------------------------------*/

/*--- Lokale Datentypen (typedef) ------------------------------------*/

/*--- Modulglobale static Variablen ----------------------------------*/

/*--- Prototypen lokaler Funktionen ----------------------------------*/

/*--- Funktionsdefinitionen ------------------------------------------*/

/*--- main -----------------------------------------------------------*/
int main(void) 
{
   // TODO
   Complex x, y;
   //Eingabe
   printf("1.Zahl eingeben\n        Realteil: ");
   scanf("%lf",&x.real);
   printf(" Imaginaeranteil: ");
   scanf("%lf",&x.imag);
   printf("2.Zahl eingeben\n        Realteil: ");
   scanf("%lf",&y.real);
   printf(" Imaginaeranteil: ");
   scanf("%lf",&y.imag);
   //Augabe der Eingegbenen Zahlen
   printf("\nx = ");
   printComplex(x);
   printf("\ny = ");
   printComplex(y);
   //Ausgabe und Berechnung
   printf("\n\nSumme: \t\tx + y = ");
   printComplex(addComplex(x,y));
   printf("\nDifferenz: \tx - y = ");
   printComplex(subComplex(x,y));
   printf("\nProdukt: \tx * y = ");
   printComplex(mulComplex(x,y));
   printf("\nQuotient: \tx / y = ");
   printComplex(divComplex(x,y));
}