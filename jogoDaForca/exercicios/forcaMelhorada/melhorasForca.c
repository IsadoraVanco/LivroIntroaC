// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

// Exercicios:
// 1)  Não permitir que o usuário digite nada além de letras maiúsculas.
// 2) Não permitir que o usuário insira uma palavra que já exista no arquivo de palavras.
// 3) Só possibilitar a inserção de uma nova palavra caso o jogador ganhe o jogo.
// 4) Pergunte ao usuário o nível de dificuldade que ele quer jogar. De acordo com o nível, você tem mais ou menos chutes.
// 5) A função enforcou() tem código repetido. 
//    Você pode fazer uso da função jachutou() e diminuir a duplicação de código.
// 6) Garanta que nosso programa funcionará bem para até 9999 palavras.
// 7) Ao final do jogo, pergunte o nome do usuário e salve-o em um arquivo ranking.txt, junto com a sua pontuação.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forcaMelhorada.h"

char palavraSecreta[TAMANHO_PALAVRA]; 
char novaPalavra[TAMANHO_PALAVRA];
char chutes[CHUTES_FACIL]; //chutes facil é a maior quatidade de chutes
int chutesDados = 0;
int pontuacao = 0; 
int qtdPalavras, totalChutes;

int main(int argc, char const *argv[]){
    
    abertura();
    escolheDificuldade();
    escolhePalavra();
    
    do{
        desenhaForca();
        chuta();

    }while(!ganhou() && !enforcou());

    printf("\nA palavra era **%s**\n", palavraSecreta);
    printf("Voce fez %d PONTOS\n", pontuacao);

    if(ganhou()){
        printf("\nParabens, voce ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("     .-\\:        /-    \n");
        printf("    | (|:.       |) |   \n");
        printf("     '-|:.       |-'    \n");
        printf("       \\::.     /      \n");
        printf("        '::.  .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

        salvaPontuacao();
        adicionaPalavra();
    }else{
        printf("\nPuxa, voce foi enforcado!\n");

        printf("        _______________        \n");
        printf("       /               \\      \n");
        printf("      /                 \\     \n");
        printf("    //                   \\    \n");
        printf("    \\|    XXXX    XXXX    |   \n");
        printf("     |    XXXX    XXXX    |    \n");
        printf("     |    XXX      XXX    |    \n");
        printf("     |                    |    \n");
        printf("     \\__      XXX      __/    \n");
        printf("       |\\     XXX      /|     \n");
        printf("       | |            | |      \n");
        printf("       | I I I I I I I  |      \n");
        printf("       |  I I I I I I   |      \n");
        printf("       \\_             _/      \n");
        printf("         \\_         _/        \n");
        printf("           \\_______/          \n");
    }
    
    return 0;
}

void abertura(){
    printf("/****************/\n");
    printf("/ Jogo da Forca */\n");
    printf("/****************/\n");
}

void chuta(){ 
    char chute;
    printf("Qual a letra? ");
    scanf(" %c", &chute); 

    int menorQueA = chute < 'A';
    int maiorQueZ = chute > 'Z';

    while(menorQueA || maiorQueZ){ 
        printf("\nChute apenas letras maiusculas!\n", chute);
        printf("Qual a letra? ");
        scanf(" %c", &chute);

        menorQueA = chute < 'A';
        maiorQueZ = chute > 'Z';
    }

    if(letraExiste(chute)){
        printf("Voce acertou: a palavra tem a letra %c\n\n", chute);
        pontuacao += 5;
    }else{
        printf("Voce errou: a palavra NAO tem a letra %c\n\n", chute);
        pontuacao -= 3;
    }

    chutes[chutesDados] = chute;
    chutesDados++;
}

int jaChutou(char letra){
    int achou = 0;

    for(int j = 0; j < chutesDados; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }

    return achou;
}

int ganhou(){
    for(int i = 0; i < strlen(palavraSecreta); i++){
        if(!jaChutou(palavraSecreta[i])){
            return 0;
        }
    }
    return 1;
}

void desenhaForca(){
    int erros = chutesErrados();

    printf("  _______  \n");
    printf(" |/      | \n");
    printf(" |     %s%s%s \n", (erros >= 1 ? "(" : " "), (erros >= totalChutes ? "x_x" : "   "), (erros >= 1 ? ")" : " "));
    printf(" |     %s%s%s \n", ((erros >= 2 && totalChutes == CHUTES_DIFICIL) || (erros >= 3 && totalChutes != CHUTES_DIFICIL) ? " /" : "  "), (erros >= 2 ? "|" : " "), 
                                ((erros >= 2 && totalChutes == CHUTES_DIFICIL) || (erros >= 3 && totalChutes == CHUTES_MEDIO) || (erros >= 4 && totalChutes == CHUTES_FACIL) ? "\\" : " "));
    printf(" |       %c \n", (erros >= 2 ? '|' : ' '));
    printf(" |    %s%c %c \n", ((erros >= 2 && totalChutes == CHUTES_DIFICIL) || (erros >= 4 && totalChutes == CHUTES_MEDIO) ? "  / \\" : "  "), 
                                (erros >= 5 && totalChutes == CHUTES_FACIL ? '/' : ' '), (erros >= 6 && totalChutes == CHUTES_FACIL ? '\\' : ' '));
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

    printf("\n");
    for(int i = 0; i < strlen(palavraSecreta); i++){

        if(jaChutou(palavraSecreta[i])){
            printf("%c ", palavraSecreta[i]);
        }else{
            printf("_ ");
        }
    }
    printf("\n\n");
}

void escolhePalavra(){
    FILE* f;
    f = fopen("palavras.txt", "r");

    if(f == 0){
        printf("Banco de dados de palavras nao disponivel.\n");
        exit(1); 
    }

    fscanf(f, "%d", &qtdPalavras); 
    srand(time(0));
    int nRandomico = rand() % qtdPalavras; 

    for(int i = 0; i <= nRandomico; i++){
        fscanf(f, "%s", palavraSecreta);
    }

    fclose(f); 
    pontuacao = strlen(palavraSecreta) * totalChutes;
}

int enforcou(){
    return chutesErrados() >= totalChutes;
}

int chutesErrados(){
    int erros = 0;

    for(int i = 0; i < chutesDados; i++){
        if(!letraExiste(chutes[i])){
            erros++;
        }
    }

    return erros;
}

int letraExiste(char letra){
    for(int j = 0; j < strlen(palavraSecreta); j++){
        if(letra == palavraSecreta[j]){
            return 1;
        }
    }
    return 0;
}

void adicionaPalavra(){
    char querAdicionar;

    printf("Voce quer adicionar uma nova palavra no jogo? (S/N) ");
    scanf(" %c", &querAdicionar);

    if(querAdicionar == 'S'){
        FILE* f;
        f = fopen("palavras.txt", "r+"); 

        if(f == 0){
            printf("Banco de dados de palavras nao disponivel.\n");
            exit(1); 
        }

        fscanf(f, "%d", &qtdPalavras);
        
        if(qtdPalavras >= MAXIMO_PALAVRAS){
            printf("Banco de palavras cheio.\n");
            fclose(f);
            exit(0);
        }

        printf("Digite com letras maiusculas: ");
        scanf(" %s", novaPalavra);
        
        while(palavraEhRepetida(f)){
            printf("\nEssa palavra ja existe no banco de dados.\n");
            printf("Digite com letras maiusculas: ");
            scanf(" %s", novaPalavra);
        }

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novaPalavra); 

        qtdPalavras++;
        
        fseek(f, 0, SEEK_SET); 
        fprintf(f, "%04d", qtdPalavras);
        
        printf("Palavra adicionada.");
        fclose(f);
    }
}

void salvaPontuacao(){
    char nome[TAMANHO_PALAVRA];
    FILE *file;
    file = fopen("ranking.txt", "a");

    printf("\nQual o seu nome? ");
    scanf("%s", nome);

    fseek(file, 0, SEEK_SET);
    fprintf(file, "%s %d\n", nome, pontuacao);

    printf("%s, sua pontuacao foi salva! Obrigada por jogar!\n", nome);
    fclose(file);
}

int palavraEhRepetida(FILE *file){
    char palavraComparativa[TAMANHO_PALAVRA];

    //deve ter algo pra pular pra segunda linha direto
    //mas por enquanto é isso :)
    fseek(file, 0, SEEK_SET); 
    fscanf(file, "%d", &qtdPalavras);

    for(int i = 0; i < qtdPalavras; i++){
        fscanf(file, "%s", palavraComparativa);
        if(strcmp(palavraComparativa, novaPalavra) == 0){
            return 1;
        }
    }

    return 0;
}

void escolheDificuldade(){
    int nivel;
    printf("\nEscolha a dificuldade:\n");
    printf("[1]FACIL [2]MEDIO [3]DIFICIL\n");
    scanf(" %d", &nivel);

    switch (nivel){
    case 1:
        printf("\n***NIVEL FACIL***\n");
        totalChutes = CHUTES_FACIL;
        break;
    
    case 2:
        printf("\n***NIVEL MEDIO***\n");
        totalChutes = CHUTES_MEDIO;
        break;
    
    default:
        printf("\n***NIVEL DIFICIL***\n");
        totalChutes = CHUTES_DIFICIL;
        break;
    }
}