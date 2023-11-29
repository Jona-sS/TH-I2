#include <stdio.h>

typedef enum {
    Salzsaure,
    Schwefelsaure,
    Salpetersaure,
    Kohlensaure,
    Anzahl_Sauren
} Saure;

typedef enum {
    Natronlauge,
    Kalilauge,
    Kalkwasser,
    Anzahl_Laugen
} Lauge;

int main() {
    const char* sauren[Anzahl_Sauren] = {"Salzsaure", "Schwefelsaure", "Salpetersaure", "Kohlensaure"};
    const char* laugen[Anzahl_Laugen] = {"Natronlauge", "Kalilauge", "Kalkwasser"};
    const char* produkte[Anzahl_Laugen][Anzahl_Sauren] = {
        {"Natriumclorid", "Natriumsulfat", "Natriumnitrat", "Natriumcarbonat"},
        {"Kaliumclorid", "Kaliumsulfat", "Kaliumnitrat", "Kaliumcarbonat"},
        {"Calciumclorid", "Calciumsulfat", "Calciumnitrat", "Calciumcarbonat"}
    };

    printf("||");
    for (int i = 0; i < Anzahl_Sauren; i++) {
        printf(" %s |", sauren[i]);
    }
    printf("\n");

    for (int i = 0; i < Anzahl_Laugen; i++) {
        printf("%s||", laugen[i]);
        for (int j = 0; j < Anzahl_Sauren; j++) {
            printf(" %s |", produkte[i][j]);
        }
        printf("\n");
    }

    return 0;
}
