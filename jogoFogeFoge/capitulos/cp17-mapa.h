// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

//tudo que é relacionado a mapa. 
//podemos reutilizar e debugar mais facilmente
//além de ficar mais organizado
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
void imprimeMapa(MAPA* m);
void encontraMapa(MAPA *m, POSICAO *p, char c);