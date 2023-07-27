// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#include <stdio.h>
#include "cp20-ui.h"
//aqui estará todos os códigos de User Interface
//ou seja, a interface do usuário

char desenhoFantasma[4][7] =  {
    {" .-.  "},
    {"| 00| "},
    {"|   | "},
    {"'^^^' "}
};

char desenhoParede[4][7] = {
    {"......"},
    {"......"},
    {"......"},
    {"......"}
};

char desenhoVazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

char desenhoHeroi[4][7] = {
    {" .--. "},
    {"/ _.-'"},
    {"\\  '-."},
    {" '--' "}
};

char desenhoPilula[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "},
};

void imprimeParte(char desenho[4][7], int parte){
    printf("%s", desenho[parte]);
}

void imprimeMapa(MAPA *m){
    for(int i = 0; i < m->linhas; i++){

        for(int parte = 0; parte < 4; parte++){ //parte do desenho da linha
            for(int j = 0; j < m->colunas; j++){
                
                switch (m->matriz[i][j]){
                
                    case FANTASMA:
                        imprimeParte(desenhoFantasma, parte);
                        break;
                    
                    case HEROI:
                        imprimeParte(desenhoHeroi, parte);
                        break;

                    case PILULA:
                        imprimeParte(desenhoPilula, parte);
                        break;

                    case VAZIO:
                        imprimeParte(desenhoVazio, parte);
                        break;

                    case PAREDE_HORIZONTAL: //ou um ou outro
                    case PAREDE_VERTICAL:
                        imprimeParte(desenhoParede, parte);
                        break;
                }
            }
            printf("\n");
        }
    }
};