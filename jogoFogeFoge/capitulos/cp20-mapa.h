// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 
#ifndef _MAPA_H_
#define _MAPA_H_

#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define PILULA 'P'

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

//um "apelido" para a estrutura mapa
typedef struct mapa MAPA;

//representam a posição do jogador no mapa
struct posicao {
    int x;
    int y;
};

typedef struct posicao POSICAO;

void leMapa(MAPA* m);
void alocaMapa(MAPA* m);
void liberaMapa(MAPA* m);
int encontraMapa(MAPA *m, POSICAO *p, char c);
int ehValida(MAPA *m, int x, int y);
int ehParede(MAPA *m, int x, int y);
int ehPersonagem(MAPA *m, char personagem, int x, int y);
int podeAndar(MAPA *m, char personagem, int x, int y);
void andaNoMapa(MAPA *m, int xOrigem, int yOrigem, int xDestino, int yDestino);
void copiaMapa(MAPA *destino, MAPA *origem);

#endif