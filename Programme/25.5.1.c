// Irren ist käferlich
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define maxMoves 150

int main()
{
    srand(time(NULL));
    int anzahl;
    //int wuerfel[2][2][2] = {{{1, 0}, {0, 0}}, {{0, 0}, {0, 0}}}; // 3D (Start[0][0][0]=1;Ziel[1][1][1]=1)                                    
    int bewegung;
    int wegLaenge;
    int haeufigkeit[maxMoves];//wie Haeufig die durch den Index angegebene Laenge benoetigt wurde
    float average;
    for(int i=0;i<maxMoves;i++){//damit keine unerwuenschten Werte verarbeitet wertden
        haeufigkeit[i]=0;
    }
    //int laengeMitHaeufigkeit[2][10];//Alternative 1D:Zuege und 2D:Haeufigkeit
    printf("Wieviel Simulationen: ");
    while (scanf("%d", &anzahl) != 1 || anzahl < 0);
    for (int i = 0; i < anzahl; i++)
    {
        int pos[3] = {0, 0, 0};  // Bildet 3D ab, 0 default 1 offset
        for(wegLaenge=0;!(pos[0]==1&&pos[1]==1&&pos[2]==1)&&wegLaenge<maxMoves;wegLaenge++)//Bis Ziel Position erreicht (Oder außerhalb des Beobachtungsbereichs)
        { //3D? wuerfel[1][1][1] != 1
            bewegung = rand() % 3; // bei 0 Bewegung in 0. Ebene usw. (es gibt je Ebene nur zwei Möglichkeiten)
            switch (bewegung)
            {
            case 0:
                if (pos[0] == 0){ // tauschen der Position in der Ebene
                    pos[0] = 1;
                }
                else{
                    pos[0] = 0;
                }
                break;
            case 1:
                if (pos[1] == 0){
                    pos[1] = 1;
                }
                else{
                    pos[1] = 0;
                }
                break;
            case 2:
                if (pos[2] == 0){
                    pos[2] = 1;
                }
                else{
                    pos[2] = 0;
                }
                break;
            }
        }
        //printf("w:%d, ",wegLaenge);
        haeufigkeit[wegLaenge]++;
    }
    for(int i=0;i<maxMoves;i++){
        average+=i*haeufigkeit[i];
    }
    average=1.0*average/anzahl;
    printf("| Weglaenge| Wieoft |\n+--------------+------------+\n|\t3  | %d |\n|\t5  | %d |\n|\t7  | %d |\n|\t9  | %d |\n|\t11 | %d |\n|\t13 | %d |\n.....................\n|\t83 | %d |\n|\t87 | %d |\nDurchschnittl. Weglaenge: **** %.2f Kanten ****"
    ,haeufigkeit[3],haeufigkeit[5],haeufigkeit[7],haeufigkeit[9],haeufigkeit[11],haeufigkeit[13],haeufigkeit[83],haeufigkeit[87],average);
}