#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "nachK.h"
#include "vorK.h"
//scanf nicht möglich da \n verarbeitet werden muss
int main(void)
{
    int vorKommaZahl, nachKommaZahl,stellenNachKomma;
    float nachKommaZahlF;
    char eingabeString[10], *vorKommaStr, *nachKommaStr;
    char *teiler =",\n";
    // Eingabe:
    printf("Gib Deine Kommazahlen ein (Abschluss mit Leerzeile)\n");
    //alternativ String einlesen
    while(1){
        fgets(eingabeString,8,stdin);//scanf nicht möglich da \n verarbeitet werden muss
        if(strlen(eingabeString)==1) break; //verlassen bei leerer Eingabe
        //String aufteilen
        vorKommaStr=strtok(eingabeString, teiler);
        nachKommaStr=strtok(NULL,teiler);
        //printf("\ts: %s , %s\n",vorKommaStr, nachKommaStr);
        //Strings in Zahlen wandeln:
        vorKommaZahl=strtol(vorKommaStr,NULL,10);
        nachKommaZahl=strtol(nachKommaStr,NULL,10);//Problem führende 0en gehen verloren
        for(stellenNachKomma = 0;nachKommaStr[stellenNachKomma]!='\0';stellenNachKomma++)
        nachKommaZahlF=1.0*nachKommaZahl/pow(10.0,stellenNachKomma+1);
        //printf("stellen nach komma%d\n",stellenNachKomma);
    	printf("\td: %d , %f\n",vorKommaZahl, nachKommaZahlF);
        //externes aufsummieren:
        addVorK(vorKommaZahl);
        addNachK(nachKommaZahlF);
    }
    printf(" %d , %f",getSummVorK(),getSummNachK());
}