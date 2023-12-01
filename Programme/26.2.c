// Argumente in Kommandozeile
// Rechnen mit Dualzahlen
#include <stdio.h>
#include <string.h>
#include <math.h>
#define ERROR 9
#define MAX_LAENGE 20

int argutmentToInt(char *argument)
{ 
    int zahl = 0;
    int leange =strlen(argument)-1;
    for (int i = 0 ; i <=leange ; i++)
    {
        if (argument[leange-i] != '0' && argument[leange-i] != '1')// Gibt ERRRO(9) zurueck wenn keine Dualzahl uebergeben wurde
        {
            printf(".......%s ist keine erlaubte Dualzahl", argument);
            return ERROR;
        }
        //printf("%c*2^%d + ",argument[leange-i],i);
        if(argument[leange-i] == '1'){
            zahl += pow(2, i);
        }
    }
    //printf("=%d\n",zahl);
    return zahl;
}
int main(int anzahl, char *argumente[])//je nach Kompiler muessen manche Operatoren in "_" gesetzt werden wird als einzigstens element ins char array gespeichert
{
    int x = 0, y = 0, z = 0, lenDualZahl=1, dualZahl[MAX_LAENGE];//dynamisch
    char operator;
    // Abbruch bei falscher Eingabe: anzahl = Menge der Argumente+1 da Nulltes Argument gleich Ausfuehrungsbefehl (.\26.2.exe)
    if (anzahl != 4)
    {
        printf("Richtiger Aufruf: dualrech <operand> <operator> <operand>\n\tErlaubte Operatoren sind: +, -, *, /, &, ^",anzahl);
        return 0;
    }
    x = argutmentToInt(argumente[1]);
    y = argutmentToInt(argumente[3]);
    operator= * argumente[2];
    switch (operator)
    {
    case '+':
        z = x + y;
        break;
    case '-':
        z = x - y;
        break;
    case '*':
        z = x * y;
        break;
    case '/':
        z = x / y;
        break;
    case '&':
        z = x & y;
        break; 
    case '^':
        z = x ^ y;
        break;
    default:
        printf(".......%c ist kein erlaubter Operator",operator); // Falsche Eingabe wenn Operation nicht gefunden
        return 0;
    }
    printf("\n%d _ %d=%d\n",x,y,z);
    if (x == ERROR || y == ERROR)
        return 0; // Bei Dualzahl Fehler hier abbrechen
    // z in Dual wandeln:
    if(z<0)z=(z-__INT_MAX__-1);//Zweierkompliment bilden
    printf("z=%d\n",z);
    for (int zDiv=z; zDiv>0 && lenDualZahl<MAX_LAENGE; lenDualZahl++)
    {
        //printf("zDiv=%d\n",zDiv%2);
        dualZahl[lenDualZahl]=zDiv%2;
        zDiv=zDiv/2;
    }
    //printf("L=%d\t",lenDualZahl);
    //Ausgabe:
    printf("%s %s %s\n.......",argumente[1],argumente[2],argumente[3]);
    for(int i=1;i!=lenDualZahl;i++){
        printf("%d",dualZahl[lenDualZahl-i]);
    }
    printf("   (0x%x)",z);
}