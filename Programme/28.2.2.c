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
    int nachKommaZwischenSpeicher,stellenNachKomma;
    //float nachKommaZahlF;
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
        zahl.vorK+=strtol(vorKommaStr,NULL,10);
        nachKommaZwischenSpeicher=strtol(nachKommaStr,NULL,10);//führende 0en gehen verloren
        for(stellenNachKomma = 0;nachKommaStr[stellenNachKomma]!='\0';stellenNachKomma++);
        printf("%d   %d",stellenNachKomma,strlen(nachKommaStr));
        zahl.nachK+=1.0*nachKommaZwischenSpeicher/pow(10.0,strlen(nachKommaStr));
        //printf("stellen nach komma%d\n",stellenNachKomma);
    	//printf("\td: %d , %f\n",zahl.vorK, zahl.nachK);
        if(zahl.nachK>=1){//Übertrag
            zahl.vorK++;
            zahl.nachK--;
        }
        printf("\t-> %d , %f\n",zahl.vorK, zahl.nachK);
    }
    printf("= %d,%d",zahl.vorK,(int)(zahl.nachK*10000.0));//Ausgabe
}