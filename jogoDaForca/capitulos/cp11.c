// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#include <stdio.h>
#include <string.h>

char palavraSecreta[20]; //aqui são variáveis globais
char chutes[27]; //agora são conhecidas por todos os escopos/funções
int tentativas = 0; //pró: economiza codigo ; contra: qual função modificou essa variavel?

void abertura();
void chuta();
int jaChutou(char letra);
void desenhaForca();
void escolhePalavra();

int main(int argc, char const *argv[]){
    int acertou = 0;
    int enforcou = 0;
 
    abertura();
    escolhePalavra();
    do{

        desenhaForca();
        // chuta(chutes, &tentativas); //chutes é o mesmo que &chutes[0]
        chuta();

        tentativas++;

    }while(!acertou && !enforcou);
    
    return 0;
}

void abertura(){
    printf("/****************/\n");
    printf("/ Jogo da Forca */\n");
    printf("/****************/\n\n");
}

void chuta(){ //um array é, por padrão, um ponteiro chutes[] = *chutes
    char chute;
    printf("Qual a letra? ");
    scanf(" %c", &chute); 

    chutes[tentativas] = chute;
    tentativas++;
}

int jaChutou(char letra){
    int achou = 0;

    for(int j = 0; j < tentativas; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaForca(){
    for(int i = 0; i < strlen(palavraSecreta); i++){

        if(jaChutou(palavraSecreta[i])){
            printf("%c ", palavraSecreta[i]);
        }else{
            printf("_ ");
        }
    }
    printf("\n");
}

void escolhePalavra(){
    sprintf(palavraSecreta, "MELANCIA");
}