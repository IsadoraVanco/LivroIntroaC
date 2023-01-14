// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#define TAMANHO_PALAVRA 20
#define MAXIMO_PALAVRAS 9999
#define CHUTES_FACIL 7
#define CHUTES_MEDIO 5
#define CHUTES_DIFICIL 3

void abertura();
void chuta();
int jaChutou(char letra);
int ganhou();
void desenhaForca();
void escolhePalavra();
int enforcou();
int chutesErrados();
int letraExiste(char letra);
void adicionaPalavra();
int palavraEhRepetida(FILE *file);
void salvaPontuacao();
void escolheDificuldade();