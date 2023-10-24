//Mischen von Farben
#include <stdio.h>
#include <string.h>

int colorToNumber(char string[]);//switch case mit string

int main(){
    char *mischMatrix[3][3] ={{"Gruen","Gelb","Blau"},{"Gelb","Rot","Purpur"},{"Blau","Purpur","Violett"}};
    //char *eingangsMatrix[3] ={"Gruen","Rot","Violett"};
    char ersteEingabe[20], zweiteEingabe[20];
    printf("Erste Grundfarbe (Gruen Rot Violett ):");
    while(scanf("%20s",ersteEingabe)!=1||(strcmp(ersteEingabe,"Gruen")&&strcmp(ersteEingabe,"Rot")&&strcmp(ersteEingabe,"Violett"))){
        printf("..... Unbekannte Grundfarbe %s (Neue Eingabe machen)",ersteEingabe);
        printf("Erste Grundfarbe (Gruen Rot Violett):");
    }
    printf("Zweite Grundfarbe (Gruen Rot Violett):");
    while(scanf("%20s",zweiteEingabe)!=1||(strcmp(zweiteEingabe,"Gruen")&&strcmp(zweiteEingabe,"Rot")&&strcmp(zweiteEingabe,"Violett"))){
        printf("..... Unbekannte Grundfarbe %s (Neue Eingabe machen)",zweiteEingabe);
        printf("Zweite Grundfarbe (Gruen Rot Violett):");
    }
    printf("..... Die Mischfarbe ist dann %s",mischMatrix[colorToNumber(ersteEingabe)][colorToNumber(zweiteEingabe)]);

}

int colorToNumber(char string[]){
    if(!strcmp(string,"Gruen")){
        return 0;
    }else if (!strcmp(string,"Rot"))
    {
        return 1;
    }else if (!strcmp(string,"Violett"))
    {
        return 2;
    }
    return 9;
}