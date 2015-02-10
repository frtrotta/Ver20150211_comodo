#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_MAXLEN 30

struct s_studente {
    char nome[NOME_MAXLEN+1];
    char cognome[NOME_MAXLEN+1];
};

typedef struct s_studente studente;

const char fname[]="studenti.dat";

const char *nomi[]= {"simone", "caterina", "alessandro", "axel", "lorenzo", "cristiano", "federico", "roland pristene", "federico", "lorenzo"};
const char *cognomi[]= {"ficola", "eracli verita'", "de angelis", "casagrande cuppoloni", "carfagna", "capretta", "braconi", "boga", "alunni", "alberetti"};
const int n=10;

int main(int argc, char** argv) {
    FILE *outputFile;
    int i;
    studente s;
    
    outputFile = fopen(fname, "wb");
    if(outputFile == NULL) {
        fprintf(stderr, "Impossibile aprire il file %s in scrittura\n", fname);
        exit(-1);
    }
    
    for(i=0; i<n; i++) {
        strcpy(s.cognome, cognomi[i]);
        strcpy(s.nome, nomi[i]);
        printf("%s; %s\n", s.cognome, s.nome);
        fwrite(&s, sizeof(studente), 1, outputFile);
    }
    fclose(outputFile);

    return (EXIT_SUCCESS);
}

