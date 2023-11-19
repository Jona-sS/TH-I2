/**********************************************************************\
* Kurzbeschreibung: complex.c
* Bietet Funktionen zum Rechnen mit komplexen Zahlen
*
* Datum:       Autor:        Grund der Aenderung:
* 
*
\**********************************************************************/

/*--- #includes ------------------------------------------------------*/
#include <float.h>
#include <stdio.h>
#include "complex.h"

/*--- #defines -------------------------------------------------------*/

/*--- Lokale Datentypen (typedef) ------------------------------------*/

/*--- Modulglobale static Variablen ----------------------------------*/

/*--- Prototypen lokaler Funktionen ----------------------------------*/

/*--- Funktionsdefinitionen ------------------------------------------*/

/*--------------------------------------------------------------------*\ 
* Addition komplexer Zahlen: x + y
* Rueckgabe: Ergebnis im Typ "Complex"
\*--------------------------------------------------------------------*/
Complex addComplex(Complex x, Complex y) 
{
   // TODO
   Complex z;
   z.real=x.real+y.real;
   z.imag=x.imag+y.imag;
   return z;
}

/*--------------------------------------------------------------------*\ 
* Subtraktion komplexer Zahlen: x - y
* Rueckgabe: Ergebnis im Typ "Complex"
\*--------------------------------------------------------------------*/
Complex subComplex(Complex x, Complex y) 
{
   // TODO
   Complex z;
   z.real=x.real-y.real;
   z.imag=x.imag-y.imag;
   return z;
}

/*--------------------------------------------------------------------*\ 
* Multiplikation komplexer Zahlen: x * y
* Rueckgabe: Ergebnis im Typ "Complex"
\*--------------------------------------------------------------------*/
Complex mulComplex(Complex y, Complex x) {
  // TODO
   Complex z;
   z.real=x.real*y.real-x.imag*y.imag;
   z.imag=x.real*y.imag+x.imag*y.real;
   return z;
}

/*--------------------------------------------------------------------*\ 
* Division komplexer Zahlen: x / y
* Rueckgabe: Ergebnis im Typ "Complex"; im Fehlerfall 0. bzw. ERROR_C
\*--------------------------------------------------------------------*/
Complex divComplex(Complex x, Complex y) 
{
   // TODO
   Complex z;
   z.real=(x.real*y.real+x.imag*y.imag)/(y.real*y.real+y.imag*y.imag);
   z.imag=(x.imag*y.real-x.real*y.imag)/(y.real*y.real+y.imag*y.imag);
   return z;
}

/*--------------------------------------------------------------------*\ 
* Lesbar formatierte Ausgabe einer komplexen Zahl
\*--------------------------------------------------------------------*/
int printComplex(Complex z) 
{
   // TODO
   printf("(%.3f + %.3fi)",z.real,z.imag);
   return 1;
}

