// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#include <stdio.h>
#include <stdlib.h>
#include "cp17-mapa.h"

void leMapa(MAPA* m){
    FILE *file;

    file = fopen("cp17.txt", "r");
    if(file == 0){
        printf("Erro na leitura do mapa.");
        exit(1);
    }

    fscanf(file, "%d %d", &(m->linhas), &(m->colunas));
    alocaMapa(m);

    for(int i = 0; i < m->linhas; i++){
        fscanf(file, "%s", m->matriz[i]);
    }

    fclose(file);
}

void alocaMapa(MAPA *m){
    m->matriz = malloc(sizeof(char*) * m->linhas);

    for(int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * m->colunas + 1);
    }
}

void liberaMapa(MAPA *m){
    for(int i = 0; i < m->linhas; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);
}

void imprimeMapa(MAPA *m){
    for(int i = 0; i < m->linhas; i++){
        printf("%s\n", m->matriz[i]);
    }
}

void encontraMapa(MAPA *m, POSICAO *p, char c){
    for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            if(m->matriz[i][j] == c){
                p->x = i;
                p->y = j;
                return;
            }
        }
    }
}
