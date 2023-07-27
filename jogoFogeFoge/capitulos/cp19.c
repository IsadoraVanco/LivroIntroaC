// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cp19.h"
#include "cp19-mapa.h"

MAPA m; 
POSICAO heroi;

int x, y;
int temPilula = 0;

void fantasmas(){
    MAPA copia;

    copiaMapa(&copia, &m);

    for(int i = 0; i < copia.linhas; i++){
        for(int j = 0; j < copia.colunas; j++){
            if(copia.matriz[i][j] == FANTASMA){
                int xDestino;
                int yDestino;

                int encontrou = paraOndeFantasmaVai(i, j, &xDestino, &yDestino);

                if(encontrou){
                    andaNoMapa(&m, i, j, xDestino, yDestino);
                }
            }
        }
    }

    liberaMapa(&copia);
}

int paraOndeFantasmaVai(int xAtual, int yAtual, int *xDestino, int *yDestino){
    int opcoes[4][2] = {
        {xAtual, yAtual + 1},
        {xAtual + 1, yAtual},
        {xAtual, yAtual - 1},
        {xAtual - 1, yAtual}
    };

    srand(time(0));

    for(int i = 0; i < 10; i++){
        int posicao = rand() % 4;

        if(podeAndar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])){
            *xDestino = opcoes[posicao][0];
            *yDestino = opcoes[posicao][1];
            return 1;
        }
    }

    return 0;
}

int acabou(){
    POSICAO pos;

    int perdeu = !encontraMapa(&m, &pos, HEROI);
    int ganhou = !encontraMapa(&m, &pos, FANTASMA);

    return perdeu || ganhou;
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

    if(!podeAndar(&m, HEROI, proximoX, proximoY)) return;

    if(ehPersonagem(&m, PILULA, proximoX, proximoY)){
        temPilula = 1;
    }
    
    andaNoMapa(&m, heroi.x, heroi.y, proximoX, proximoY);

    heroi.x = proximoX;
    heroi.y = proximoY;
}

void explodeBomba(){

    for(int i = 1; i <= 3; i++){
        if(ehValida(&m, heroi.x, heroi.y)){
            if(ehParede(&m, heroi.x, heroi.y)) break;

            m.matriz[heroi.x][heroi.y] = VAZIO;
        }
    }
}

int main(int argc, char const *argv[]){

    leMapa(&m);
    encontraMapa(&m, &heroi, HEROI);

    do{
        printf("Pilula: %s \n\n", (temPilula ? "SIM" : "NÃO"));
        imprimeMapa(&m);

        char comando;
        scanf(" %c", &comando);
        
        if(ehDirecao(comando)) move(comando);
        if(comando == BOMBA) explodeBomba();

        fantasmas();
    } while(!acabou());

    liberaMapa(&m);

    return 0;
}
