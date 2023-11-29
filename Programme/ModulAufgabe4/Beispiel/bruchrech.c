/**********************************************************************\
 * Kurzbeschreibung:
 * bruchrech.c - realisiert einen einfachen Bruchrechner
 *
 * Datum:     Autor:
 * 30.9.2015  Prof. Dr. Helmut Herold
\**********************************************************************/

/*--- #includes ------------------------------------------------------*/
#include "bruchrech.h"

/*--- #defines -------------------------------------------------------*/

/*--- Datentypen (typedef) -------------------------------------------*/

/*--- Definition modul-lokaler Funktionen ----------------------------*/

/*--------------------------------------------------------------------*/
static int  ggT(int n, int m)
{
   return (m==0) ? n : ggT(m, n%m);
}

/*--------------------------------------------------------------------*/
static Bruch kuerze(Bruch b)
{
   int  ggTeiler = ggT(b.zaehler, b.nenner);
   b.zaehler /= ggTeiler;
   b.nenner  /= ggTeiler;
   return b;
}

/*--- Definition globaler Funktionen ---------------------------------*/

/*--------------------------------------------------------------------*\ 
 * addiert die beiden übergebenen Brüche und liefert Ergebnisbruch
\*--------------------------------------------------------------------*/
Bruch add(Bruch b1, Bruch b2)
{
   b1.zaehler = b1.zaehler * b2.nenner + b2.zaehler * b1.nenner;
   b1.nenner = b1.nenner * b2.nenner;
   return kuerze(b1);
}

/*--------------------------------------------------------------------*\ 
 * subtrahiert die beiden übergebenen Brüche und liefert Ergebnisbruch
\*--------------------------------------------------------------------*/
Bruch sub(Bruch b1, Bruch b2)
{
   b1.zaehler = b1.zaehler * b2.nenner - b2.zaehler * b1.nenner;
   b1.nenner  = b1.nenner * b2.nenner;
   return kuerze(b1);
}

/*--------------------------------------------------------------------*\ 
 * multipliziert die beiden übergebenen Brüche und liefert Ergebnisbruch
\*--------------------------------------------------------------------*/
Bruch mul(Bruch b1, Bruch b2)
{
   b1.zaehler = b1.zaehler * b2.zaehler,
   b1.nenner  = b2.nenner * b2.nenner;
   return kuerze(b1);
}

/*--------------------------------------------------------------------*\ 
 * dividiert die beiden übergebenen Brüche und liefert Ergebnisbruch
\*--------------------------------------------------------------------*/
Bruch divi(Bruch b1, Bruch b2)
{
   b1.zaehler = b1.zaehler * b2.nenner;  /* Mit Kehrbruch multiplizieren */
   b1.nenner = b1.nenner * b2.zaehler;
   return kuerze(b1);
}
