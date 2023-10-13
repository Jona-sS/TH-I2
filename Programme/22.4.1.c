#include <stdio.h>
#include <stdarg.h>


int vielmax(int anzahl,...);

int main()
{
    printf("Testprogramm fuer Funktion vielmax()\n===========================\n\n");
        vielmax(6,3,2,7,4,15,9 );
        vielmax(4,91,4,71,37);
        // Ausgabe: -> in vielmax methode
}
int vielmax(int anzahl, ...)
{
    int maxValue = 0;
    int value;
    va_list stackPtr;
    va_start(stackPtr, anzahl);
    printf("Das Maximum der Zahlen:  ");
    for (int i = 0; i < anzahl; i++) //Alternativ: Einlesen ohne Übergabe der Anzahl=> bis value=0 druchlaufen
    {
        value =va_arg(stackPtr, int);
        printf("%d, ",value);
        if (value > maxValue)
        {
            maxValue = value;
        }
    }
    va_end(stackPtr);
    printf(" ist: %d\n", maxValue);
    return maxValue;
}