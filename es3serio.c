/*
Si vuole realizzare un programma in C per la gestione di un archivio di album
musicali (al massimo 100). Ogni album è caratterizzato da un titolo ed un autore
(entrambe stringhe di al massimo 30 caratteri), un anno di pubblicazione, il
numero di tracce, la durata complessn iva (itermdiini  ore, minuti, secondi); infine,
si vuole memorizzare anche il prezzo dell'album (un valore float).

Definire un tipo di dato per rappresentare l'archivio di album. In seguito scrivere un
programma che chiede al l'utente prima il numero di album da inserire e poi i dati di
ciascun album (assumendo chel'utente inserisca correttamente i dati). 

programma visualizza i dati dell'album di durata massima; se sono presenIlti più
album di stessa durata massima il programma visualizzerà i dati del primo di essi
(VARIANTE: il programma visualizza i dati di tutti gli album di durata massima, se
ne sono stati trovati più di uno).
In seguito il programma chiede il nome di un autore e visualizza i titoli di tutti gli
album pubblicati da questo. Infine il programma visualizza l'autore che ha
pubblicato più album; se più autori autori hanno lo stesso numero massimo di
album, si visualizzi il primo.
*/
#include <stdio.h>
#include <string.h>

typedef struct {
    int ore;
    int minuti;
    int secondi;
} Durata;

typedef struct {
    char titolo[30], autore[30];
    int anno;
    int tracce;
    Durata durata;
    float prezzo;
} Album;

typedef Album Archivio[100];

// Calculate the total duration of an album in seconds
int calcolare_durata(Album *album) {
    return (album->durata.ore * 3600) + (album->durata.minuti * 60) + album->durata.secondi;
}

// Find and print the album with the maximum duration
void durata_massima(Archivio *archivio, int numero) {
    int massimo_index = 0; // Index of the album with the maximum duration
    long massimo_valore = 0; // Maximum duration in seconds

    for (int i = 0; i < numero; i++) {
        long attuale = calcolare_durata(&(*archivio)[i]);
        if (attuale > massimo_valore) {
            massimo_valore = attuale;
            massimo_index = i;
        }
    }

    // Print details of the album with the maximum duration
    Album max_album = (*archivio)[massimo_index];
    printf("\nL'album con durata massima e':\n");
    printf("Titolo: %s\n", max_album.titolo);
    printf("Autore: %s\n", max_album.autore);
    printf("Durata: %d:%02d:%02d\n", max_album.durata.ore, max_album.durata.minuti, max_album.durata.secondi);
    printf("Anno: %d\n", max_album.anno);
    printf("Prezzo: %.2f\n", max_album.prezzo);
}

// Display all albums by a specific author
void controllo_autore(Archivio *archivio, char autore[30], int numero) {
    int found = 0;
    printf("\nAlbum pubblicati da %s:\n", autore);
    for (int i = 0; i < numero; i++) {
        if (strcmp((*archivio)[i].autore, autore) == 0) {
            found = 1;
            printf("Titolo: %s\n", (*archivio)[i].titolo);
        }
    }
    if (!found) {
        printf("Nessun album trovato per l'autore %s.\n", autore);
    }
}

// Find the author with the most albums
void piu_album(Archivio *archivio, int numero) {
    char autori[100][30];
    int conteggi[100] = {0};
    int autori_unici = 0;

    // Count the albums for each author
    for (int i = 0; i < numero; i++) {
        int found = 0;
        for (int j = 0; j < autori_unici; j++) {
            if (strcmp((*archivio)[i].autore, autori[j]) == 0) {
                conteggi[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(autori[autori_unici], (*archivio)[i].autore);
            conteggi[autori_unici] = 1;
            autori_unici++;
        }
    }

    // Find the author with the maximum number of albums
    int max_index = 0;
    for (int i = 1; i < autori_unici; i++) {
        if (conteggi[i] > conteggi[max_index]) {
            max_index = i;
        }
    }

    printf("\nL'autore con il maggior numero di album e': %s\n", autori[max_index]);
}

int main() {
    int numero;
    Archivio archivio;

    printf("Inserire il numero di album che vuole inserire: ");
    scanf("%d", &numero);

    // Input album details
    for (int i = 0; i < numero; i++) {
        printf("\nInserire i dati dell'album numero %d:\n", i + 1);
        printf("Titolo: ");
        scanf(" %[^
]s", archivio[i].titolo);
        printf("Autore: ");
        scanf(" %[^
]s", archivio[i].autore);
        printf("Anno: ");
        scanf("%d", &archivio[i].anno);
        printf("Tracce: ");
        scanf("%d", &archivio[i].tracce);
        printf("Durata (ore minuti secondi): ");
        scanf("%d %d %d", &archivio[i].durata.ore, &archivio[i].durata.minuti, &archivio[i].durata.secondi);
        printf("Prezzo: ");
        scanf("%f", &archivio[i].prezzo);
    }

    // Find and display the album with the maximum duration
    durata_massima(&archivio, numero);

    // Find and display all albums by a specific author
    char autore[30];
    printf("\nInserire il nome dell'autore da controllare: ");
    scanf(" %s", autore);
    controllo_autore(&archivio, autore, numero);

    // Find and display the author with the most albums
    piu_album(&archivio, numero);

    return 0;
}
