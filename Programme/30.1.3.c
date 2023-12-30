#include "stdio.h"
#define MAX 20

int main(){
    FILE *datei;
    char daten[8][MAX];
    char datenart[8][MAX]={{"Vorname\t"},{"Nachname"},{"Strasse\t"},{"Hausnummer"},{"Postleitzahl"},{"Wohnort\t"},{"Telefon\t"},{"Fax\t"}};
    int anzahl;
    printf("Dieses Programm liest eine Adresse ein und schreibt\ndiese Adresse n mal in die Datei 'adresse.txt'\n");
    for(int i =0;i<8;i++){
        printf("%s: ",datenart[i]);
        scanf("%s",daten[i]);
        //fgets(daten[i],MAX,stdin);//fget kopiert bis einschließlich \n
    }
    printf("Wie oft soll Adresse in Datei geschrieben werden: ");
    scanf("%d",&anzahl);
    datei=fopen("adresse.txt","w");
    for(int i = 0; i<anzahl;i++){
        fprintf(datei,"%s %s \n%s %s\n%s %s\n\n",daten[0],daten[1],daten[2],daten[3],daten[4],daten[5]);
        fprintf(datei,"Tel. %s\nFax  %s\n",daten[6],daten[7]);
        fprintf(datei,"--------------------------------------\n");
    }
    fclose(datei);
}