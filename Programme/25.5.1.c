// Irren ist käferlich
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define maxMoves 150

void ausgabe(int haeufigkeit[], float average);

int main()
{
    srand(time(NULL));
    int anzahl, bewegung, wegLaenge;                                  
    int haeufigkeit[maxMoves];//wie Haeufig die durch den Index angegebene Laenge benoetigt wurde
    float average;
    for(int i=0;i<maxMoves;i++){//damit keine unerwuenschten Werte verarbeitet wertden
        haeufigkeit[i]=0;
    }
    printf("Wieviel Simulationen: ");//Eingabe
    while (scanf("%d", &anzahl) != 1 || anzahl < 0);
    for (int i = 0; i < anzahl; i++)
    {
        int pos[3] = {0, 0, 0};//Positionsbeschreibung in 3Achsen, jeweils 0=Default und 1=Offset
        for(wegLaenge=0;!(pos[0]==1&&pos[1]==1&&pos[2]==1)&&wegLaenge<maxMoves;wegLaenge++)//Bis Ziel Position erreicht (Oder außerhalb des Beobachtungsbereichs)
        {
            bewegung = rand() % 3; // bei 0 Bewegung in 0. Ebene usw. (es gibt je Ebene nur zwei Lage Möglichkeiten)
            switch (bewegung)
            {
            case 0:
                pos[0]=!pos[0];// tauschen der Position in der Ebene
                break;
            case 1:
                pos[1]=!pos[1];
                break;
            case 2:
                pos[2]=!pos[2];
                break;
            }
        }
        //printf("w:%d, ",wegLaenge);
        haeufigkeit[wegLaenge]++;//Abspeichern der benötigten Weglänge
    }
    for(int i=0;i<maxMoves;i++){//
        average+=i*haeufigkeit[i];
    }
    average=1.0*average/anzahl;
    ausgabe(haeufigkeit, average);
}
void ausgabe(int haeufigkeit[], float average){//gibt die benötigte Zuege mit ihrer Häufigkeit aus
    printf("| Weglaenge|     Wieoft |\n+----------+------------+\n");
    
    for(int i = 1; i < maxMoves; i += 2){
        if(haeufigkeit[i] != 0){
            printf("| %8d | %10d |\n", i, haeufigkeit[i]);
        }
    }

    printf("\tDurchschnittl. Weglaenge:    **** %5.3f Kanten ****\n", average);
}