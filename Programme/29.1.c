//Mischtabelle Chemie
#include <stdio.h>
#include <string.h>
//https://www.youtube.com/watch?v=ziPqD60GTSU
//enumerator: Definiert Integer Konstanten in einen Datentyp, nur die aufegelisteten Namen koennen umgewandelt werden
//            wird Zahlenwert nicht mit angegeben fortlaugend durchnummeriert
//            nutzen um Switch case übersichtlicher zu machen
//tpedef: Datentyp wird einer Varible zugewiesen/ Defenitionen umbenenen

enum saure{
    Salzsaure,//als Startwert nutzen und bis Anzahl Itterieren und Printen
    Schwefelsaure,
    Salpetersaure =2, //Variablen werden nacheinander druchnummeriert
    Kohlensaure,
    Anzahl_Sauren
};
typedef enum {
    Natronlauge,
    Kalilauge,
    Kalkwasser,
    Anzahl_Laugen//Verwendung bei Deklaration schmeist jedoch Warung weil angeblich veränderbar
}lauge;
#define ANZAHL_SAEUREN 4
#define ANZAHL_LAUGEN 3
int main(){
    typedef const char datentyp;//Definition von datentyp
    datentyp *mischMatrix[ANZAHL_SAEUREN][ANZAHL_LAUGEN] ={{"Natriumclorid","Kaliumclorid","Calciumclorid"},{"Natriumsulfat","Kaliumsulfat","Calciumsulfat"},{"Natriumnitrat","Kaliumnitrat","Calciumnitrat"},{"Natriumcarbonat","Kaliumcarbonat","Calciumcarbonat"}};
    datentyp *sauren[ANZAHL_SAEUREN] = {"Salzsaure", "Schwefelsaure", "Salpetersaure", "Kohlensaure"};
    datentyp *laugen[ANZAHL_LAUGEN] = {"Natronlauge", "Kalilauge", "Kalkwasser"};
    printf("\t\t||");
    for (enum saure printSaure = Salzsaure; printSaure < Anzahl_Sauren; printSaure++) {//Aufruf mit enum erhöht die lesbarkeit, hinter Salzsaure steht die 0 =>alternativ int i=0
        printf(" %16s |", sauren[printSaure]);
    }
    printf("\n----------------||------------------|------------------|------------------|------------------|\n");
    for (lauge printLauge = Natronlauge;printLauge < Anzahl_Laugen; printLauge++) {//typedef bei der enum Beschreibung erspaart das enum in der deklaration
        printf("%16s||", laugen[printLauge]);
        for (enum saure printSaure = Salzsaure; printSaure < Anzahl_Sauren; printSaure++) {
            printf(" %16s |", mischMatrix[printLauge][printSaure]);
        }
        printf("\n");
    }
}