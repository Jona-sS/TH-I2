//Folgen von Nullen und Einsen
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_LENGTH 1000

void ausgabe(int zahlen[MAX_LENGTH],int length);

int main()
{
    srand(time(NULL));
    int zahlen[MAX_LENGTH];
    int zahlen_komprimiert[MAX_LENGTH];
    int length;
    printf("Laenge der 0/1-Folge (max. 1000): ");
    while(scanf("%d",&length)!=1||length<=0||length>1000){
        printf("Falsche Eingabe\nLänge der 0/1-Folge (max. 1000): ");
    }
    //Zufalls Werte generieren:
    for (int i = 0; i < length; i++)
    {
        zahlen[i]=rand()%2;
    }
            //Nötig falls Zahlen ein char Array: (dann auch Ausgabe ohne Schleife möglich)
            //zahlen[length] = '\0'; // Nullterminator
    ausgabe(zahlen, length);
    //Komprimieren:
    while (length > 1) {
        int compressedLength = 0;
        for (int i = 0; i < length - 1; i=i+2) {
            if (zahlen[i] == zahlen[i + 1]) {
                zahlen_komprimiert[compressedLength++] = 0;
            } else {
                zahlen_komprimiert[compressedLength++] = 1;
            }
        }
        if(length%2){//leztes Bit bei ungerader Länge übernehmen
            zahlen_komprimiert[compressedLength++]=zahlen[length-1];
        }
                //zahlen_komprimiert[compressedLength] = '\0';
                //printf("%s\n", zahlen_komprimiert); // Ausgabe der komprimierten Sequenz
        length = compressedLength;
        for (int i = 0; i < length; i++) {
            zahlen[i] = zahlen_komprimiert[i]; // Kopiere die komprimierte Sequenz in sequence
        }
        ausgabe(zahlen, length);
    }   
}
void ausgabe(int zahlen[MAX_LENGTH], int length){
    for(int i=0; i<length;i++){
        printf("%d",zahlen[i]);
    }
    printf("\n");
}