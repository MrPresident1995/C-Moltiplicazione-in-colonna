#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 3

void mul(int *v1, int *v2, int n, int *v3);

int main()
{
    int i;
    char num[MAX+1];
    int num1[MAX];
    int num2[MAX];
    int num3[MAX*2];

    //IMPOSTAZIONE
    for(i=0; i<MAX; i++)
    {
        num1[i]= 0;
        num2[i]= 0;
    }
    for(i=0; i<MAX*2; i++)
        num3[i]= 0;

    //INPUT
    printf("Inserire un numero da %d cifre: ", MAX);
    scanf("%s", num);
    for(i=0; i<MAX; i++)
        num1[i]= (int)num[i]-48;
    printf("Inserire un numero da %d cifre: ", MAX);
    scanf("%s", num);
    for(i=0; i<MAX; i++)
        num2[i]= (int)num[i]-48;

    //ESECUZIONE
    mul(num1, num2, MAX, num3);

    //CHIUSURA
    printf("\n\nIl risultato della moltiplicazione e': ");
    for(i=0; i<MAX*2; i++)
        printf("%d", num3[i]);
    return 0;
}

void mul(int *v1, int *v2, int n, int *v3)
{
    int i;
    int o;
    int p;
    int l;
    int somma;
    int matrice_calcolo[n][n*2];

    for(i=0; i<n; i++)
        for(o=0; o<n*2; o++)
            matrice_calcolo[i][o]= 0;

    p= n-1;
    l= n-1;
    for(i=0; i<n; i++)
    {
        o= n*2-(i+1);
        while(p>=0)
        {
            somma= v1[p] * v2[l];
            while(somma>=10)
            {
                somma= somma-10;
                matrice_calcolo[i][o-1]++; //DECINE
            }
            matrice_calcolo[i][o]= matrice_calcolo[i][o] + somma; //UNITA'
            p--;
            o--;
        }
        p= n-1; //RIMETTE IN POSIZIONE NUM1
        l--; //PASSA AL SECONDO NUMERO DI NUM2
    }

    for(i=n*2-1; i>0; i--) //CALCOLO RISULTATO
    {
        somma= 0;
        for(o=0; o<n; o++)
        {
            somma= somma + matrice_calcolo[o][i];
            if(somma>=10)
            {
                somma= somma-10;
                *(v3+i-1)= *(v3+i-1)+1;
            }
        }
        *(v3+i)= *(v3+i) + somma;
    }
}
