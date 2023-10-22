//Streichen eines Zeichens aus String
#include <stdio.h>
#include <string.h>
int main(){
    char string[1000];
    char newString[1000];
    char deletChar;
    int z =0;
    printf("Geben Sie eine Zeichenkette (max. 1000 Zeichen) ein:\n");
    scanf("%100[^\n]s",string);
    while(getchar()!='\n');
    printf("Geben Sie das zu loeschende Zeichen ein:");
    while(scanf("%c", &deletChar)!=1||deletChar<'A'||deletChar>'z');
    for(int i=0;i<strlen(string);i++){
        if(string[i]!=deletChar){ //Nicht Übereinstimmende Zeichen in neuen String kopieren
            newString[i-z]=string[i];
        }else{
            z++; //Indexverschiebung damit keine Lücke an den Stellen des Zeichens entsteht
        }
    }
    newString[strlen(string)-z] ='\0';//mit Nullzeichen neunen Array zu String machen
    printf("......Die neue Zeichenkette ist dann: %s",newString);
}