//Ausgabe des Programms
#include <stdio.h>
int i=0;
int main(void)
{
int i=1;
printf("i=%d\n", i);
{
int i=2;
printf("i=%d\n", i);
{
i++;
printf("i=%d\n", i);
}
printf("i=%d\n", i);
}
printf("i=%d\n", i);
return(0);
}