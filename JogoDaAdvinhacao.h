// Baseado no livro 'Introdução a C' de Mauricio Ariche 

#include <stdio.h> //standart I/O (entrada e saída padrão)

int main(){ //função principal
    printf("************************************\n");
    printf("* Bem vindo ao Jogo da Adivinhação *\n");
    printf("************************************\n");

    int numeroSecreto;
    int chute;

    printf("Qual é o seu chute?");
    scanf("%d", &chute); //%d é o tipo int
    printf("Seu chute foi %d \n", chute);

    if(chute == numeroSecreto){
        printf("Parabéns! Você acertou! \n");
    }else{
        printf("Você errou! \n");

        if(chute > numeroSecreto){
            printf("O número secreto é menor que seu chute. \n");
        }else{
            printf("O número secreto é maior que seu chute. \n");
        }
    }
}