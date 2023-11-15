#include <stdio.h>
#include <string.h>
//LEVIN Ich Sehe Das Du Da Warst
struct zeit //Struct anlegen
{
    int tag;
    int std;
    int min;
    int sek;
};

struct zeit eingabe(int i) //Funktion zum Einlesen der Daten
{
    struct zeit z;

    printf("Gib %d. Zeit ein: (tt.hh.mm.ss): ", i);
    while (scanf("%d.%d.%d.%d", &z.tag, &z.std, &z.min, &z.sek) != 4 || z.tag < 0 || z.std < 0 || z.std > 23 || z.min < 0 || z.min > 59 || z.sek < 0 || z.sek > 59 )
    {
        printf("Falsche Eingabe. Gib %d. Zeit ein: (tt.hh.mm.ss): ", i);
        int c;
        while ((c = getchar()) != '\n' && c != 0); //Eingabepuffer wird bis ungleich \n gelehrt bzw bis EOF
    }
    return z;
}

unsigned long zeit_int_sek(struct zeit z) //Umrechnung in Sekunden
{
    unsigned long sekunden = 0;
    sekunden += z.tag * 86400;
    sekunden += z.std * 3600;
    sekunden += z.min * 60;
    sekunden += z.sek;
    return sekunden;
}

struct zeit sek_in_zeit(unsigned long sek) //Zurückrechnen ind d/h/m/s
{
    struct zeit z;                          
    z.tag = sek / 86400;
    z.std = (sek % 86400) / 3600;
    z.min = ((sek % 86400) % 3600) / 60;
    z.sek = ((sek % 86400) % 3600) % 60;

    return z;
}

int main()
{
    struct zeit z1; // Erstes struct erstellt
    struct zeit z2; // Zweites struct erstellt

    z1 = eingabe(1); //Funktion für Eingabe holen
    z2 = eingabe(2);

    unsigned long sekunden = zeit_int_sek(z1) + zeit_int_sek(z2);   //Berechnung in Sekunden Gesamt

    z1 = sek_in_zeit(sekunden); //Sekunden übergeben um Struct wieder neuzubefüllen
    printf("...... = %d Tage, %0d:%0d.%0d; %lu Gesamtsekunden\n", z1.tag, z1.std, z1.min, z1.sek,sekunden); //Ausgabe des Struct 

    return 0;
}
