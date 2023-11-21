#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
#define MAX_GESAMT 200

//LEVIN ICH SEHE DICH ! GRUSS

struct nameList //Struct erstellt 
{
    char *list1[MAX];
    char *list2[MAX];
    char *listEntire[MAX_GESAMT];
};

void eingabe(struct nameList *ptr, int *list1Anzahl, int *list2Anzahl)
{
    int const ZeichenMax = 50;
    char input[ZeichenMax];
    int lenght = 0;
    *list1Anzahl = 0;
    *list2Anzahl = 0;
    printf("Name (Beenden mit Enter): ");
    while (fgets(input, ZeichenMax, stdin) != 0 ) // Einlesen des ersten Strings/Namen
    {
        if (strlen(input) == 1 && input[0] == '\n') //Wenn Enter gedrückt wird wird die Eingabe abgebrochen
            break;
        
        lenght = strlen(input);
        if (input[lenght - 1] == '\n') // Ersetzen des Enterzeichens durch \0
            input[lenght - 1] = '\0';

        int listNr = 0;
        printf("Welche Liste (1 oder 2): "); //Einlesen der Liste
        while (scanf("%d", &listNr) != 1 || (listNr != 1 && listNr != 2))   //Überprufung auf Ungleich 1 und 2
        {
            printf("Falsche Eingabe. Bitte 1 oder 2 wählen: ");
            while (getchar() != '\n');
        }
        while (getchar() != '\n'); //Löschen des Enterzeichens im Eingabepuffer
        
        if (listNr == 1)    //Schreiben in die Liste im struct
        {
            ptr->list1[*list1Anzahl] = (char*)malloc(strlen(input)+1); //Speicher freigeben und /0 (Deshalb +1)
            strcpy(ptr->list1[*list1Anzahl],input); //Eingabestring in die Liste copieren
            (*list1Anzahl)++;
        }
        else if (listNr == 2)
        {
            ptr->list2[*list2Anzahl] = (char*)malloc(strlen(input)+1); //Speicher freigeben und /0 (Deshalb +1)
            strcpy(ptr->list2[*list2Anzahl],input); //Eingabestring in die Liste copieren
            (*list2Anzahl)++;
        }
        printf("Name (Beenden mit Enter): ");
    }
 }
static int compareName(const void *vergleich1, const void *vergleich2){

    return stricmp(*(char**)vergleich1,*(char**)vergleich2); //char** Zeiger auf die Zeichekentte die verglichen wird Rückgabe 0 bei Gleichheit >0 Zeichen größer, <0 kleiner

}
void listSort(struct nameList *ptr,int List1Anzahl, int List2Anzahl){

    qsort(ptr->list1,List1Anzahl,sizeof(ptr->list1[0]),compareName);    // <0 1 Element an erste  Stelle , >0 Element an die Zweite.
    qsort(ptr->list2,List2Anzahl,sizeof(ptr->list2[0]),compareName);
    qsort(ptr->listEntire,List1Anzahl+List2Anzahl,sizeof(ptr->listEntire[0]),compareName);
}
void listGesamt(struct nameList *ptr,int List1Anzahl, int List2Anzahl){

    for (int i = 0; i < (List1Anzahl); i++)
    {
            ptr->listEntire[i] = (char*)malloc(strlen(ptr->list1[i])+1);    //Speicher freigeben und /0 (Deshalb +1)
            strcpy(ptr->listEntire[i],ptr->list1[i]); //Eingabestring 1 in die Gesamtliste kopieren
    }
    for (int i = 0; i < (List2Anzahl); i++)
    {
            ptr->listEntire[List1Anzahl+i] = (char*)malloc(strlen((ptr->list2[i])+1));  //Speicher freigeben und /0 (Deshalb +1)
            strcpy(ptr->listEntire[List1Anzahl+i],ptr->list2[i]); //Eingabestring 2 in die Gesamtliste kopieren
    } 
}
void ausgabe(char *Ausgabe[],int Anzahl){

    for (int i = 0; i < Anzahl; i++)
    {
        printf("%d. Name: %s\n",i+1,Ausgabe[i]);
    }
    printf(".....Listenende.....\n\n");
}

int main()
{
    struct nameList Namen; //struct Liste mit dem Namen Namen erstellt 
    struct nameList *ptrNamen; // Pointer auf den Struct erstellt
    int list1Anzahl, list2Anzahl; //Zählervariablen für die Anzahl an Namen Pro liste erstellt 

    ptrNamen = &Namen; // Zeiger auf das Struct Namen intitialisiert

    // Eingabe der Namen und schreiben in Liste 1 und 2
    eingabe(ptrNamen,&list1Anzahl,&list2Anzahl);
    //List 1 und 2 zusammenfügen in Gesamtliste
    listGesamt(ptrNamen,list1Anzahl,list2Anzahl);

    listSort(ptrNamen,list1Anzahl,list2Anzahl); // Alle Listen werden sortiert
    printf("..... 1. Liste.....\n");
    ausgabe(ptrNamen->list1,list1Anzahl); // Ausgabe Liste 1
    printf("..... 2. Liste.....\n"); 
    ausgabe(ptrNamen->list2,list2Anzahl);   // Ausgabe Liste 1
    printf("..... Gemischte Liste.....\n");
    ausgabe(ptrNamen->listEntire,(list1Anzahl+list2Anzahl)); // Ausgabe Liste 1

    //free(ptrNamen->list1);
    //free(ptrNamen->list2);
    //free(ptrNamen->listEntire);

    return 0;
}
