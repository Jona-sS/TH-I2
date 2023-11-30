#include <stdio.h>
#include <string.h>
#define MAX 200
#define BEGRENZUNG 2000

int main()
{
    FILE *datei; // Datenzeigervariable von der stdio.h lib. Damit kann man aus dem Programm heraus auf eine Datei zugreifen
    char dateiname[MAX];
    char wort[MAX];
    char input[MAX];
    char *teiler = " \n";

    printf("Bitte gebe: suchtext: 'WORT' 'dateiname.txt' ein\n");
    printf("User = suchtext: ");
    fgets(input, MAX, stdin); // Einlesen des Strings
    int count = 0;
    char *token = strtok(input, teiler);
    while (token != NULL) // Zerteilen des strings auf 1 Wort und Dateinamen
    {
        if (count == 0)
            strcpy(wort, token);
        else if (count == 1)
            strcpy(dateiname, token);

        token = strtok(NULL, teiler);
        count++;
    }

    datei = fopen(dateiname, "r"); // Überpruefung ob Datei gefunden und geöffnet werden kann/Schaut in das verzeichnis wo die Datei leigt. Sonst muss Pfad angegebnw werden
                                   //  z.B. const char *pfad = "/Pfad/zur/deiner/Datei/beispiel.txt"; mit strcat zusammenfügen
    if (datei == 0)
    {
        printf("Die Datei kann nicht geöffnet werden"); // Falls es nicht geöffnet werden kann, close
        return -1;
    }
    char buffer[BEGRENZUNG]; // Bregezung für Anzahl der Zeichen die gelesen werden können
    int vorhanden = 1;
    while (fgets(buffer, sizeof(buffer), datei) != NULL)
    {

        if (strstr(buffer, wort)) // Kommt Wert vor soll die kommplette Zeile ausgeben werden
            printf("%d. %s\n", vorhanden, buffer);

        vorhanden++; // Hochzählen damit man weiß in welcher Zeile das Wort vorkommt
    }
    return 0;
}
