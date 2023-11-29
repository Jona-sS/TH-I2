/**********************************************************************\
 * Kurzbeschreibung:
 * TestBruchrech.c - realisiert einen einfachen Bruchrechner
 *
 * Datum:     Autor:
 * 30.9.2015  Prof. Dr. Helmut Herold
\**********************************************************************/

/*--- #includes ------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS //VC++: keine scanf() Warnungen
#include <stdio.h>
#include "bruchrech.h"

/*--- #defines -------------------------------------------------------*/

/*--- Datentypen (typedef) -------------------------------------------*/

/*--- Prototypen lokaler Funktionen ----------------------------------*/
static Bruch bruch_einlesen(void);

/*--- main -----------------------------------------------------------*/
int main(void)
{
   int fehler;
   char op;
   Bruch b1, b2;

   printf("\nBitte 1. Bruch eingeben:\n");
   b1 = bruch_einlesen();
   printf("\nBitte 2. Bruch eingeben:\n");
   b2 = bruch_einlesen();

   do {
      fehler = 0;
      printf("\nBitte gewuenschte Operation eingeben!");
      printf("(+,-,*,/)");
      printf("\nIhre Wahl:");
      scanf("%c", &op); getchar();

      switch (op) {
         case '+': 
		    b1 = add (b1, b2); 
			break;
         case '-': 
		    b1 = sub (b1, b2); 
			break;
         case '*': 
		    b1 = mul (b1, b2); 
			break;
         case '/': 
		    b1 = divi(b1, b2); 
			break;
         default:
            fehler = 1;
            fprintf(stderr, "\n.......Falsche Eingabe!\n");
            break;
      }
   } while ( fehler == 1 );
   
   printf("\n   ==> %d/%d\n", b1.zaehler, b1.nenner);
   
   return 0;
}

/*--- bruch_einlesen -------------------------------------------------*/
static Bruch bruch_einlesen(void)
{
   Bruch b;
   int nr;
   
   do {
      printf("Zaehler (ungleich 0!): ");
      nr = scanf("%d", &b.zaehler); getchar();
   } while (nr != 1 || b.zaehler == 0);
   
   do {
      printf("Nenner (ungleich 0!): ");
      nr = scanf("%d", &b.nenner); getchar();
   } while (nr != 1 || b.nenner == 0);
   
   return b;
}

