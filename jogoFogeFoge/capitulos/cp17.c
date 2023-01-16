// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#include <stdio.h>
#include <stdlib.h>
#include "cp17.h"

//agrupar dados que devem ficar perto é uma boa pratica!
MAPA m; // mesmo que:
// struct mapa m;

// char **mapa;
// int linhas, colunas;

int main(int argc, char const *argv[]){

    leMapa();

    do{
        imprimeMapa();

        char comando;
        scanf("%c", &comando);
        move(comando);
    } while(!acabou());

    liberaMapa();

    return 0;
}

void leMapa(){
    FILE *file;

    file = fopen("cp17.txt", "r");
    if(file == 0){
        printf("Erro na leitura do mapa.");
        exit(1);
    }

    fscanf(file, "%d %d", &(m.linhas), &(m.colunas));
    alocaMapa();

    for(int i = 0; i < m.linhas; i++){
        fscanf(file, "%s", m.matriz[i]);
    }

    fclose(file);
}

void alocaMapa(){
    m.matriz = malloc(sizeof(char*) * m.linhas);

    for(int i = 0; i < m.linhas; i++){
        m.matriz[i] = malloc(sizeof(char) * m.colunas + 1);
    }
}

void liberaMapa(){
    for(int i = 0; i < m.linhas; i++){
        free(m.matriz[i]);
    }
    free(m.matriz);
}

int acabou(){
    return 0;
}

void imprimeMapa(){
    for(int i = 0; i < m.linhas; i++){
        printf("%s\n", m.matriz[i]);
    }
}

void move(char direcao){
    int x, y;

    for(int i = 0; i < m.linhas; i++){
        for(int j = 0; j < m.colunas; j++){
            if(m.matriz[i][j] == '@'){
                x = i;
                y = j;
                break;
            }
        }
    }

    switch(direcao){
        case 'a':
            m.matriz[x][y - 1] = '@';
            break;
        case 'w':
            m.matriz[x - 1][y] = '@';
            break;
        case 's':
            m.matriz[x + 1][y] = '@';
            break;
        case 'd':
            m.matriz[x][y + 1] = '@';
            break;    
    }

    m.matriz[x][y] = '.';
}