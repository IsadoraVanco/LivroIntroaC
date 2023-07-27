// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 
#ifndef _FOGEFOGE_H_
#define _FOGEFOGE_H_

#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define BOMBA 'b'

void fantasmas();
int paraOndeFantasmaVai(int xAtual, int yAtual, int *xDestino, int *yDestino);
int acabou();
int ehDirecao(char direcao);
void move(char direcao);

#endif