// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

//um "apelido" para a estrutura mapa
typedef struct mapa MAPA;

void leMapa();
void alocaMapa();
void liberaMapa();
int acabou();
void imprimeMapa();
void move(char direcao);