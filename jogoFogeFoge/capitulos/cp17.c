// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#include <stdio.h>
#include <stdlib.h>
#include "cp17.h"
#include "cp17-mapa.h"

//para que a variável global também seja lida em outros módulos,
//é necessário utilizar a palavra chave 'extern' antes do tipo
MAPA m; 

// char **mapa;
// int linhas, colunas;

int acabou(){
    return 0;
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

int main(int argc, char const *argv[]){

    leMapa(&m);

    do{
        imprimeMapa(&m);

        char comando;
        scanf("%c", &comando);
        move(comando);
    } while(!acabou());

    liberaMapa(&m);

    return 0;
}
