#include <stdio.h>

long umwandlung(long zahl);

int main()
{
    int zahl;
    printf("Gib eine Dezimalzahl ein: ");
    scanf("%d", &zahl);
    umwandlung(zahl);
}

long umwandlung(long zahl)
{
    if (zahl < 0)
    { // Zweierkompliment bei negativen Zahlen
    zahl=0xFFFFFFF+zahl+1;
    }
    //printf("zahl: %d\n", zahl);
    if (zahl == 0)
    {
        return 1;
    }
    if (umwandlung(zahl / 2) == 1)
    {
        printf("%d", zahl % 2);
    }
}