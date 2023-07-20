// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#include <stdio.h>
#include <stdlib.h>
#include "cp16.h"

char **mapa;
// char mapa[5][11]; //com 1 posição a mais nas linhas para o \n
int linhas, colunas;


void leMapa(){
    FILE *file;

    file = fopen("cp16.txt", "r");
    if(file == 0){
        printf("Erro na leitura do mapa.");
        exit(1);
    }

    fscanf(file, "%d %d", &linhas, &colunas);
    alocaMapa();

    for(int i = 0; i < linhas; i++){
        fscanf(file, "%s", mapa[i]);
    }

    fclose(file);
}

void alocaMapa(){
    mapa = malloc(sizeof(char*) * linhas);

    for(int i = 0; i < linhas; i++){
        mapa[i] = malloc(sizeof(char) * colunas + 1);
    }
}

void liberaMapa(){
    for(int i = 0; i < linhas; i++){
        free(mapa[i]);
    }
    free(mapa);
}

int main(int argc, char const *argv[]){

    leMapa();

    for(int i = 0; i < linhas; i++){
        printf("%s\n", mapa[i]);
    }

    liberaMapa();

    return 0;
}
