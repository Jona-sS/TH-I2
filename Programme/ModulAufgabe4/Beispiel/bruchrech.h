/**********************************************************************\
 * Kurzbeschreibung:
 * bruchrech.h - realisiert einen einfachen Bruchrechner
 *
 * Datum:     Autor:
 * 30.9.2015  Prof. Dr. Helmut Herold
\**********************************************************************/
#ifndef BRUCHRECH_H
#define BRUCHRECH_H

/*--- #includes ------------------------------------------------------*/

/*--- #defines -------------------------------------------------------*/

/*--- Datentypen (typedef) -------------------------------------------*/
typedef struct {
   int zaehler;
   int nenner;
} Bruch;

/*--- Prototypen globaler Funktionen ---------------------------------*/

/*--------------------------------------------------------------------*\ 
 * addiert die beiden übergebenen Brüche und liefert Ergebnisbruch
\*--------------------------------------------------------------------*/
Bruch add (Bruch b1, Bruch b2);

/*--------------------------------------------------------------------*\ 
 * subtrahiert die beiden übergebenen Brüche und liefert Ergebnisbruch
\*--------------------------------------------------------------------*/
Bruch sub (Bruch b1, Bruch b2);

/*--------------------------------------------------------------------*\ 
 * multipliziert die beiden übergebenen Brüche und liefert Ergebnisbruch
\*--------------------------------------------------------------------*/
Bruch mul (Bruch b1, Bruch b2);

/*--------------------------------------------------------------------*\ 
 * dividiert die beiden übergebenen Brüche und liefert Ergebnisbruch
\*--------------------------------------------------------------------*/
Bruch divi(Bruch b1, Bruch b2);

#endif /*BRUCHRECH_H*/
