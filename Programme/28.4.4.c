//Strukturarrays
//Notenübersicht und Notenspiegel

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *name;
    char *vorname;
    int note;
}Student;

int eingabe(int nr, Student *student){
    student->name = malloc(10 * sizeof(char));
    student->vorname = malloc(10 * sizeof(char));
    printf("----Eingabe des %d.Schuelers----\nName:\t\t",nr+1);
    fgets(student->name,10, stdin);
    if(strlen(student->name)==1){//Abbruch bei Enter Eingabe
        return 0;
    }
    if (student->name[strlen(student->name) - 1] == '\n') // Löschen des Enterzeichens
        student->name[strlen(student->name) - 1] = '\0';
    printf("Vorname:\t");
    fgets(student->vorname,10, stdin);
    if (student->vorname[strlen(student->vorname) - 1] == '\n') // Löschen des Enterzeichens
        student->vorname[strlen(student->vorname) - 1] = '\0';
    printf("Note:\t\t");
    while(scanf("%d",&student->note)!=1||student->note>6||student->note<1){
        printf("gebe eine richtige Note ein: ");
        while(getchar()!='\n');
    }
    while(getchar()!='\n');
    return 1;
}

int main(){
    Student *klasse;
    int nr=0;
    float durchschnitt;
    klasse=(Student *)malloc(sizeof(Student));
    //Eingabe:
    while(eingabe(nr,&klasse[nr])){
        klasse = (Student *)realloc(klasse,sizeof(Student)*(nr+2));//Speicher fuer naechsten Studenten alokieren
        nr++;
    }
    //Auswertung:
    printf("\t\tName\t\t, Vorname\t\t, Note\n-----------------------------------------------------------------------------\n");
    //Druchschnitt ermitteln:
    for(int i=0;i<nr;i++){
        printf("%6d. \t%s\t\t, %s\t\t,  %d\n",i+1,klasse[i].name,klasse[i].vorname,klasse[i].note);
        durchschnitt+=klasse[i].note;
    }
    printf("\n....Druchschnittsnote: %.2f",durchschnitt/nr);
    //Notenverteilungs Statistik:
    printf("\n....Notenspiegel");
    for (int n = 1; n <= 6; n++)
    {
        printf("\nNote %d: ",n);
        for (int i = 0; i < nr; i++)
        {
            if(klasse[i].note==n)
            printf("*");
        }
    }
}