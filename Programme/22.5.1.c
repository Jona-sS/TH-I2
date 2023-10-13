//22.5.1
#include <stdio.h>

int binKoeff(int n, int k);

int main(){
    int n, k;
    printf("Wieviele Positionen: ");
    while(scanf("%d",&n)!=1||n<=0){
        printf("Fehlerhafte Eingabe (<0)\nWieviele Positionen: ");
    }
    printf("Wievlele Elemente (muss <= %d sein): ",n);
    while(scanf("%d",&k)!=1||k<0||k>n){
        printf("Fehlerhafte Eingabe (<0 oder Elemente>Positionen)\nWievlele Elemente (muss <= %d sein): ",n);
    }
    printf("  / %d\t\\\n |\t | = %d\n  \\   %d\t/",n,binKoeff(n,k),k);
}
int binKoeff(int n, int k){
    if(k==0||k==n){
        return 1;
    }else{
        return binKoeff(n-1,k) + binKoeff(n-1,k-1);
    }
}