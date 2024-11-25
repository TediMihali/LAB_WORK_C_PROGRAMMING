/*
Scrivere un programma in C che acquisisce una sequenza di al più 20 valori interi,
chiedendo all'utente inizialmente quanti valori vorrà fornire, num. Il programma
acquisisce num valori e memorizza in una opportuna struttura dati la sequenza di
valori i cui elementi sono strettamente crescenti, trascurando i valori che risultano
non essere ordinati. Al termine dell'acquisizione il programma visualizza la
lunghezza della sequenza, seguita, su una nuova riga, dalla sequenza stessa.
L'utente inserirà sempre un numero di valori coerente con la richiesta.
*/
#include<stdio.h>
#define MAX_LEN 20

int main(){
    int valori[MAX_LEN], numero;

    printf("Quanti numeri buole inserire?");
    scanf("%d", &numero);

    int i;
    printf("Inserisci numeri in sequenza senza interruzione");
    for(i=0; i<numero; i++){
        scanf("%d", &valori[i]);
    }

    int monotona[MAX_LEN];

    monotona[0] = valori[0];
    int j = 1;
    for(i=1; i<numero; i++){
        if(valori[i] > monotona[j-1]){
            monotona[j] = valori[i];
            j++;
        }
    }
-
    printf("La lunghezza della sequenza e %d e la sequenza e: \n", j);
    for(i=0; i<j; i++){
        printf("%d", monotona[i]);
    }
}