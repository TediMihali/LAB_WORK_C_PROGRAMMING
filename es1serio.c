/*
Scrivere un programma in C che acquisisce una sequenza di al più 100 valori interi
e un intero strettamente positivo k. L'acquisizione della sequenza termina quando
l'utente inserisce un numero negativo o nullo, oppure quando vengono acquisiti
100 valori. Il programma visualizza 1 se la sequenza contiene almeno una coppia di
valori tali che la loro somma sia k, 0 altrimenti. Dopo il valore visualizzato, mettere
un 'a-capo'.
*/

#include<stdio.h>
#define MAX_LEN 100

int main(){

int valori[MAX_LEN];
int valore, k, dim, flag;

dim = 0; 
valore = 99999;
flag = 0;
while(valore > 0 && dim < 100 && flag == 0){
    scanf("%d", &valore);
    if(valore > 0){
        valori[dim] = valore;
        dim ++;
    } else{
        flag = 1;
    }
}
printf("%d", dim);
printf("\nInserire il valore k");
scanf("%d", &k);

int i, j;
flag = 0;
for(i = 0; i  < dim && flag == 0; i++){
    for(int j= i + 1; j < dim && flag == 0; j++){
        if(valori[i] + valori[j] == k)
            flag = 1;
    }
}

printf("%d", flag);

}