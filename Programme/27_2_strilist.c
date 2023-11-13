#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZEICHEN 1000
#define MAX 10

int main()
{
    char eingabe[ZEICHEN];
    char *strichliste[MAX] = {0};
    int zaehler[MAX] = {0};
    char *vergleich[MAX] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    //char ersatzString[MAX];

    while (fgets(eingabe, ZEICHEN, stdin) != 0) // Eingabe bis EOF = Strg-Z 
    {
        int lenght = strlen(eingabe);
        if (eingabe[lenght - 1] == '\n') // Löschen des Enterzeichens
            eingabe[lenght - 1] = '\0';

        for (int k = 0; k < MAX; k++) //Ziffer waehlen und druchgehen
        {
            for (int i = 0; eingabe[i] != '\0'; i++)
            {
                if (vergleich[k][0] == eingabe[i]) //Abgleichen der Eingabe mit einer Ziffer
                {
                    zaehler[k]++;   // Zaehlstand erhöht 
                }
            }
        }
    }

    for (int i = 0; i < MAX; i++) //Jeden Zustand zwischen 0 ... 9 durchgehen
    {
        strichliste[i] = (char *)malloc(zaehler[i] + 1); // Wegen dem String Abschluss muss \0 berücksichtigt werden (Bsp. 5 (zaehler[i] + 1 = 6 Positionen in der Strichliste ))
        for (int k = 0; k < zaehler[i]; k++)
        {
            strichliste[i][k] = '|';    // Strichliste erstellen
        }
        strichliste[i][zaehler[i]] = '\0'; // \0 hinzufügen

        printf("%s: %s\n", vergleich[i], strichliste[i]); // Ausgabe
                                                          
        free(strichliste[i]); // Speicherplatz freigeben
    }

    return 0;
}