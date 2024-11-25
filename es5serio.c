/*
 Scrivere un programma in C che riceve in ingresso un array di 10 valori numeri
 interi. Costruire un nuovo array dove in corrispondenza di ogni elemento dell'array
 iniziale si mette:
 0 se l'elemento i è non strettamente positivo,
 1 se l'elemento i è un numero perfetto,
 2 se l'elemento i è abbondante,
 3 se l'elemento i è difettivo
 Per definizione un numero è perfetto se corrisponde alla somma dei suoi divisori,
 escluso se stesso; abbondante se è minore della somma dei suoi divisori, escluso
 se stesso; altrimenti è difettivo. Ad esempio: 6 e 28 sono perfetti, 12 e 18 sono
 abbondanti, mentre 8 e 10 sono difettivi.
Il programma visualizza i valori inseriti, su una nuova riga la caratteristica del
 numero, ed infine un istogramma verticale che rappresenta la quantità di numeri
 perfetti, difettivi e abbondanti contenuti nell'array iniziale
*/

#include<stdio.h>
#define MAX_LEN 10

int tipo_numero(int*);

void istogramma(int [3]);

int main(){
    int numeri[MAX_LEN], i;

    printf("Inserire i numeri del array");
    for(i=0; i<MAX_LEN; i++){
        scanf("%d", &numeri[i]);
    }

    int tipi_numeri[MAX_LEN];
    for(i=0; i<MAX_LEN; i++){
        tipi_numeri[i] = tipo_numero(&numeri[i]);
    }

    printf("La lista dei numeri e: \n");
    for(i=0; i<MAX_LEN; i++){
        printf("%d", tipi_numeri[i]);
    }

    int counts[3] = {0};
    for(i=0; i<MAX_LEN; i++){
        if(tipi_numeri[i] == 1){
            counts[0]++;
        } else if(tipi_numeri[i] == 2){
            counts[1]++;
        } else{
            counts[2]++;
        }
    }
    istogramma(counts);
}

int tipo_numero(int *numero){
    int somma = 0;
    for(int i=1; i<*numero; i++){
        if(*numero % i == 0){
            somma += i;
        }
    }

    if(*numero <= 0){
        return 0;
    } else if(somma == *numero){
        return 1;
    } else if(somma > *numero){
        return 2;
    }
    else{
        return 3;
    }
}

void istogramma(int counts[3]){
      int max_count = 0;

    // Find the maximum count
    for (int i = 0; i < 3; i++) {
        if (counts[i] > max_count) {
            max_count = counts[i];
        }
    }

    // Print the histogram vertically
    for (int i = max_count; i > 0; i--) {
        for (int j = 0; j < 3; j++) {
            if (counts[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("1 2 3\n"); // Labels for Perfect, Abundant, and Deficient
}