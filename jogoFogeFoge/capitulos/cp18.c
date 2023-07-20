// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#include <stdio.h>
#include <stdlib.h>
#include "cp18.h"
#include "cp18-mapa.h"

//para que a variável global também seja lida em outros módulos,
//é necessário utilizar a palavra chave 'extern' antes do tipo
MAPA m; 
//representa as coordenadas do jogador no mapa
POSICAO heroi;

int x, y;

int acabou(){
    return 0;
}

int ehDirecao(char direcao){
    return
        direcao == CIMA ||
        direcao == BAIXO ||
        direcao == ESQUERDA ||
        direcao == DIREITA;
}

void move(char direcao){

    if(!ehDirecao(direcao)) return;

    int proximoX = heroi.x;
    int proximoY = heroi.y;

    switch(direcao){
        case ESQUERDA:
            proximoY--;
            break;
        case CIMA:
            proximoX--;
            break;
        case BAIXO:
            proximoX++;
            break;
        case DIREITA:
            proximoY++;
            break;    
    }

    if(!ehValida(&m, proximoX, proximoY)) return;
    if(!ehVazia(&m, proximoX, proximoY)) return;
    
    andaNoMapa(&m, heroi.x, heroi.y, proximoX, proximoY);

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
