// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#include <stdio.h>
#include <string.h>

char palavraSecreta[20]; 
char chutes[27]; 
int tentativas = 0;

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

void chuta(){ 
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