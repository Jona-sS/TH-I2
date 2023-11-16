//Mischtabelle Chemie
#include <stdio.h>
#include <string.h>
//https://www.youtube.com/watch?v=ziPqD60GTSU
//enumerator: Definiert Integer Konstanten in einen Datentyp, nur die aufegelisteten Namen koennen umgewandelt werden
//            wird Zahlenwert nicht mit angegeben fortlaugend durchnummeriert
//            nutzen um Switch case übersichtlicher zu machen
//tpedef: Datentyp wird einer Varible zugewiesen/ Defenition umbenenen

enum Saure{
    Salzsaure,//als Startwert nutzen und bis Anzahl Itterieren und Printen
    Schwefelsaure,
    Salpetersaure,
    Kohlensaure,
    Anzahl_Sauren
};

enum Lauge{
    Natronlauge,
    Kalilauge,
    Kalkwasser,
    Anzahl_Laugen//Verwendung bei Deklaration schmweist jedoch Warung weil angeblich veränderbar
};
#define ANZHAHL_SAEUREN 4
#define ANZAHL_LAUGEN 3
int main(){
    typedef const char vorgabe;//Definition von Vorgabe
    vorgabe *mischMatrix[ANZHAHL_SAEUREN][ANZAHL_LAUGEN] ={{"Natriumclorid","Kaliumclorid","Calciumclorid"},{"Natriumsulfat","Kaliumsulfat","Calciumsulfat"},{"Natriumnitrat","Kaliumnitrat","Calciumnitrat"},{"Natriumcarbonat","Kaliumcarbonat","Calciumcarbonat"}};
    vorgabe *sauren[ANZHAHL_SAEUREN] = {"Salzsaure", "Schwefelsaure", "Salpetersaure", "Kohlensaure"};
    vorgabe *laugen[ANZHAHL_SAEUREN] = {"Natronlauge", "Kalilauge", "Kalkwasser"};
    
    printf("\t\t||");
    printf(" %16s |", sauren[Salzsaure]);//Aufruf mit enum erhöht die lesbarkeit
    for (int i = 1; i < Anzahl_Sauren; i++) {
        printf(" %16s |", sauren[i]);
    }
    printf("\n----------------||------------------|------------------|------------------|------------------|\n");
    for (int i = 0; i < Anzahl_Laugen; i++) {
        printf("%16s||", laugen[i]);
        for (int j = 0; j < Anzahl_Sauren; j++) {
            printf(" %16s |", mischMatrix[i][j]);
        }
        printf("\n");
    }
}