/*
 Scrivere un programma in C che acquisita una stringa di al più 30 caratteri,
 individui la sottostringa più lunga in essa contenuta, senza caratteri ripetuti. Il
 programma visualizza la lunghezza di tale sottostringa, seguita da un carattere a-capo
*/

#include <stdio.h>
#include <string.h>
#define MAX_LEN 30

int main()
{
    char stringa[MAX_LEN + 1];

    printf("Inserire la stringa");
    scanf("%s", stringa);

    int start = 0;
    int length = 0;
    int i, j;
    for (i = 0; i < strlen(stringa); i++)
    {
        for(j=i - 1; j>=0; j--){
            if(stringa[i] == stringa[j] || stringa[i] == '\0'){
                if(i - start > length){
                    length = i - start;
                }
                start = i;
            }
        }
    }

    printf("La lunghezza della sottostringa piu lunga e %d", length);
}