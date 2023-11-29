#include <stdio.h>
#include <string.h>
#include <math.h>
#define ERROR 9
#define MAX_Laenge 20
// Argumente in Kommandozeile
// Rechnen mit Dualzahlen
int argutmentToInt(char *argument)
{ 
    int zahl = 0;
    for (int i = 0; i < strlen(argument); i++)
    {
        if (argument[i] != '0' && argument[i] != '1')// Gibt ERRRO(9) zurueck wenn keine Dualzahl uebergeben wurde
        {
            printf(".......%s ist keine erlaubte Dualzahl", argument);
            return ERROR;
        }
        zahl += (int)argument[i] * pow(2, i);
    }
    return zahl;
}
int main(int anzahl, char *argumente[])
{
    int x = 0, y = 0, z = 0, lenDualZahl, dualZahl[MAX_Laenge];//dynamisch
    char operator;
    // Abbruch bei falscher Eingabe: anzahl = Menge der Argumente+1
    if (anzahl < 4)
    {
        printf("Richtiger Aufruf: dualrech <operand> <operator> <operand>\n\tErlaubte Operatoren sind: +, -, *, /, &, ^");
        return 0;
    }
    x = argutmentToInt(argumente[1]); // 1 da Nulltes Argument gleich Ausfuehrungsbefehl (.\26.2.exe)
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
    if (x == ERROR || y == ERROR)
        return 0; // Bei Dualzahl Fehler hier abbrechen
    // z in Dual wandeln:
    if(z<0)z=__INT_MAX__-z;//Zweierkompliment bilden

    for (lenDualZahl = 0; z>0 && lenDualZahl<MAX_Laenge; lenDualZahl++)
    {
        dualZahl[lenDualZahl]=z%2;
        //dualZahl[MAX_Laenge-i]=z%2;//Array von hinten auffuellen     alternativ von hinten ausgeben
        z=z/2;//?testen
    }
    //Ausgabe:
    printf("%s %s %s\n.......",argumente[1],argumente[2],argumente[3]);
    for(int i=0;i<MAX_Laenge;i++){
        printf("%d",dualZahl[lenDualZahl-1]);
    }
    printf("   (0x%x)",z);
}