//Mischen von Farben
#include <stdio.h>
#include <string.h>

int colorToNumber(char string[]);//switch case mit string

int main(){
    char mischMatrix[3][3] ={{"Gruen","Gelb","Blau"},{"Gelb","Rot","Purpur"},{"Blau","Purpur","Violett"}};
    char eingangsMatrix[3] ={"Gruen","Rot","Violett"};
    char ersteEingabe[], zweiteEingabe[];
    printf("Erste Grundfarbe (Grün Rot Violett ):");
    while(scanf("%10s",ersteEingabe)!=1||!(ersteEingabe=="Gruen"&&ersteEingabe=="Gelb"&&ersteEingabe=="Blau")){
        printf("..... Unbekannte Grundfarbe %s (Neue Eingabe machen)",ersteEingabe);
        printf("Erste Grundfarbe (Grün Rot Violett ):");
    }
    printf("Zweite Grundfarbe (Grün Rot Violett ):");
    while(scanf("%10s",zweiteEingabe)!=1||!(zweiteEingabe=="Gruen"&&zweiteEingabe=="Gelb"&&zweiteEingabe=="Blau")){
        printf("..... Unbekannte Grundfarbe %s (Neue Eingabe machen)",zweiteEingabe);
        printf("Zweite Grundfarbe (Grün Rot Violett ):");
    }
    printf("..... Die Mischfarbe ist dann %s",mischMatrix[colorToNumber(ersteEingabe)][colorToNumber(zweiteEingabe)]);

}

int colorToNumber(char string[]){
    if(string=="Gruen"){
        return 0;
    }else if (string=="Rot")
    {
        return 1;
    }else if (string=="Violett")
    {
        return 2;
    }
    return 9;
}