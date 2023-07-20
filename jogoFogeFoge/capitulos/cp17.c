// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#include <stdio.h>
#include <stdlib.h>
#include "cp17.h"
#include "cp17-mapa.h"

//para que a variável global também seja lida em outros módulos,
//é necessário utilizar a palavra chave 'extern' antes do tipo
MAPA m; 
//representa as coordenadas do jogador no mapa
POSICAO heroi;

int x, y;

int acabou(){
    return 0;
}

void move(char direcao){
    //os fors foram substituidos por variaveis globais que indicam a posição

    m.matriz[heroi.x][heroi.y] = '.';

    switch(direcao){
        case 'a':
            m.matriz[heroi.x][heroi.y - 1] = '@';
            break;
        case 'w':
            m.matriz[heroi.x - 1][heroi.y] = '@';
            break;
        case 's':
            m.matriz[heroi.x + 1][heroi.y] = '@';
            break;
        case 'd':
            m.matriz[heroi.x][heroi.y + 1] = '@';
            break;    
    }
}

int main(int argc, char const *argv[]){

    leMapa(&m);
    encontraMapa(&m, &heroi, '@');

    do{
        imprimeMapa(&m);

        char comando;
        scanf("%c", &comando);
        move(comando);
    } while(!acabou());

    liberaMapa(&m);

    return 0;
}
