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

    if(
        direcao != 'a' &&
        direcao != 'w' &&
        direcao != 's' &&
        direcao != 'd' 
    ) return;

    int proximoX = heroi.x;
    int proximoY = heroi.y;

    switch(direcao){
        case 'a':
            proximoY--;
            break;
        case 'w':
            proximoX--;
            break;
        case 's':
            proximoX++;
            break;
        case 'd':
            proximoY++;
            break;    
    }

    if(proximoX >= m.linhas) return;
    if(proximoY >= m.colunas) return;
    
    if(m.matriz[proximoX][proximoY] != '.') return;

    m.matriz[proximoX][proximoY] = '@';
    m.matriz[heroi.x][heroi.y] = '.';
    heroi.x = proximoX;
    heroi.y = proximoY;
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
