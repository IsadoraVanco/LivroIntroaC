// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "cp12.h" //esta no mesmo diretorio

char palavraSecreta[20]; 
char chutes[27]; 
int chutesDados = 0;

int main(int argc, char const *argv[]){
    
    abertura();
    escolhePalavra();
    
    do{

        desenhaForca();
        chuta();

    }while(!ganhou() && !enforcou());

    adicionaPalavra();

    printf("\n FIM DE JOGO\n");
    
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
        exit(1); //termina a aplicação. o 1 sinaliza ao SO que houve um erro
    }

    int qtdPalavras;
    fscanf(f, "%d", &qtdPalavras); // a leitura em um arquivo é sequencial!
    //ou seja, ela continua de onde parou
    srand(time(0));
    int nRandomico = rand() % qtdPalavras; //escolhe um número aleatorio entre o numero maximo de palavras

    for(int i = 0; i <= nRandomico; i++){
        fscanf(f, "%s", palavraSecreta);
    }

    fclose(f); //fecha a aplicação para que outros programas possam usa-lo 
}

int enforcou(){
    int erros = 0;

    for(int i = 0; i < chutesDados; i++){
        int existe = 0;

        for(int j = 0; j < strlen(palavraSecreta); j++){
            if(chutes[i] == palavraSecreta[j]){
                existe = 1;
                break;
            }
        }

        if(!existe){
            erros++;
        }
    }

    return erros >= 5; //cabeça, tronco, braços, pernas e fim
}

void adicionaPalavra(){
    char querAdicionar;

    printf("Voce quer adicionar uma nova palavra no jogo? (S/N)");
    scanf(" %c", &querAdicionar);

    if(querAdicionar == 'S'){
        char novaPalavra[20];

        printf("Digite (letras maiusculas): ");
        scanf("%s", novaPalavra);

        FILE* f;
        // f = fopen("cp12.txt", "a"); //a = append (adicionar ao final do arquivo)
        f = fopen("cp12.txt", "r+"); //r = reading e + escrever

        if(f == 0){
            printf("Banco de dados de palavras nao disponivel.\n");
            exit(1); //termina a aplicação. o 1 sinaliza ao SO que houve um erro
        }

        int qtdPalavras;
        fscanf(f, "%d", &qtdPalavras);
        qtdPalavras++;

        //arquivo, qtd de bytes que devem andar, onde deve começar
        fseek(f, 0, SEEK_SET); //começo do arquivo
        //escreve "por cima"
        fprintf(f, "%d", qtdPalavras);

        fseek(f, 0, SEEK_END); //final do arquivo
        fprintf(f, "\n%s", novaPalavra); //escreve a palavra ao final do arquivo
        
        fclose(f); //o arquivo precisa ser fechado para ser alterado
    }
}