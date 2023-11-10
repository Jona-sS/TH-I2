#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct zahl{
    int vorK;
    float nachK;
};
//scanf nicht möglich da \n verarbeitet werden muss
int main(void)
{
    struct zahl zahl;
    int nachKommaZwischenSpeicher;
    //float nachKommaZahlF;
    char eingabeString[10], *vorKommaStr, *nachKommaStr;
    char *teiler =",\n\0";
    // Eingabe:
    printf("Gib Deine Kommazahlen ein (Abschluss mit Leerzeile)\n");
    while(1){
        fgets(eingabeString,8,stdin);//scanf nicht möglich da \n verarbeitet werden muss
        if(strlen(eingabeString)==1) break;//Beenden bei leerer Eingabe
        //String aufteilen
        vorKommaStr=strtok(eingabeString, teiler);
        nachKommaStr=strtok(NULL,teiler);
        //Strings in Zahlen wandeln:
        zahl.vorK+=strtol(vorKommaStr,NULL,10);
        nachKommaZwischenSpeicher=strtol(nachKommaStr,NULL,10);//führende 0en gehen verloren
        zahl.nachK+=1.0*nachKommaZwischenSpeicher/pow(10.0,strlen(nachKommaStr));//Umwandlung in nachkomma float
        if(zahl.nachK>=1){//Übertrag
            zahl.vorK++;
            zahl.nachK--;
        }
        //printf("\t-> %d , %f\n",zahl.vorK, zahl.nachK);
    }
    printf("= %d,%d",zahl.vorK,(int)(zahl.nachK*10000.0));//Ausgabe
}