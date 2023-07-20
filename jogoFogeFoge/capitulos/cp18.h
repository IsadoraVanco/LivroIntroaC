// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'

#define FANTASMA 'F'

void fantasmas();
int paraOndeFantasmaVai(int xAtual, int yAtual, int *xDestino, int *yDestino);
int acabou();
int ehDirecao(char direcao);
void move(char direcao);