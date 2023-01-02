// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

char palavraSecreta[TAMANHO_PALAVRA]; 
char chutes[27]; 
int chutesDados = 0;

int main(int argc, char const *argv[]){
    
    abertura();
    escolhePalavra();
    
    do{

        desenhaForca();
        chuta();

    }while(!ganhou() && !enforcou());

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
    }else{
        printf("\nPuxa, voce foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavraSecreta);

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

    adicionaPalavra();

    // printf("\n FIM DE JOGO\n");
    
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

    if(letraExiste(chute)){
        printf("Voce acertou: a palavra tem a letra %c\n\n", chute);
    }else{
        printf("Voce errou: a palavra NAO tem a letra %c\n\n", chute);
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

    printf("  _______      \n");
    printf(" |/      |     \n");
    //usando ifs ternários (condição ? verdadeiro : falso)
    printf(" |      %c%c%c    \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c    \n", (erros >= 2 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 2 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 3 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
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
    f = fopen("cp12.txt", "r");

    if(f == 0){
        printf("Banco de dados de palavras nao disponivel.\n");
        exit(1); 
    }

    int qtdPalavras;
    fscanf(f, "%d", &qtdPalavras); 
    srand(time(0));
    int nRandomico = rand() % qtdPalavras; 

    for(int i = 0; i <= nRandomico; i++){
        fscanf(f, "%s", palavraSecreta);
    }

    fclose(f); 
}

int enforcou(){
    return chutesErrados() >= 5;
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

    printf("Voce quer adicionar uma nova palavra no jogo? (S/N)");
    scanf(" %c", &querAdicionar);

    if(querAdicionar == 'S'){
        char novaPalavra[TAMANHO_PALAVRA];

        printf("Digite (letras maiusculas): ");
        scanf("%s", novaPalavra);

        FILE* f;
        f = fopen("palavras.txt", "r+"); 

        if(f == 0){
            printf("Banco de dados de palavras nao disponivel.\n");
            exit(1); 
        }

        int qtdPalavras;
        fscanf(f, "%d", &qtdPalavras);
        qtdPalavras++;

        fseek(f, 0, SEEK_SET); 
        fprintf(f, "%d", qtdPalavras);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novaPalavra); 
        
        fclose(f);
    }
}