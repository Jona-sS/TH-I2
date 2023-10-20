// Ersetzen von Wörtern in einem String
#include <stdio.h>
#include <string.h>

void edit(char string[],char suche[],char ersetze[]);

int main()
{
    char string[100], suche[100], ersetze[100], j_oder_n = 'j';
    int druchfuehren = 1;
    printf("Gib einen String ein:\n");
    scanf("%1000[^\n]s", string);
    while(getchar()!='\n');
    while(druchfuehren){
        printf("Welches Wort soll ersetzt werden: ");
        scanf("%100[^\n]s", suche);
        while(getchar()!='\n');
        printf("Durch welches Wort soll dieses ersetzt werden: ");
        scanf("%100[^\n]s", ersetze);
        while(getchar()!='\n');

        edit(string,suche,ersetze);

        printf(".....Neuer String:%s", string);
        printf("\nNoch eine Ersetzung (j/n): ");
        j_oder_n=getchar();
        while(!(j_oder_n == 'n' || j_oder_n == 'j'))
        {
            while(getchar()!='\n');
            printf("Ungueltige Eingabe!\nNoch eine Ersetzung (j/n): ");
            j_oder_n=getchar();
        }
        while(getchar()!='\n');
        if (j_oder_n == 'n')
        {
            druchfuehren = 0;
        }
    }
}
void edit(char string[],char suche[],char ersetze[]){
    char* ptr =strstr(string,suche);
    while(ptr!=NULL){
        //Überprüfung ob es ein alleinstehendes Wort ist:
        if((*(ptr-1)==' '||ptr==string)&&(*(ptr+strlen(suche))==' '||*(ptr+strlen(suche))=='\0')){
            strncat(ersetze,ptr+strlen(suche),strlen(string)-(string-ptr)-strlen(suche));//hinteren Stringteil an ersetze heangen
            strncpy(ptr,ersetze,strlen(ersetze));//copy ohne Nullzeichen ->fügt nur ein =>Problem wenn suche länger als ersetze
            *(ptr+strlen(ersetze))='\0'; //Haendisches einsetzten des Nullzeichens
        }
        ptr=strstr(ptr+1,suche); //nach weiteren Vorkommen suchen
    }
}