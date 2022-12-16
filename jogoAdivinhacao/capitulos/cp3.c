// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#include <stdio.h> //standart I/O (entrada e saída padrão)

int main(){ //função principal
    int numerosecreto;
    int chute;

    printf("************************************\n");
    printf("* Bem vindo ao Jogo da Adivinhacao *\n");
    printf("************************************\n");

    numerosecreto = 42;
    // imprimindo somente o número
    // printf("%d", 42);

    printf("Qual e o seu chute? ");
    scanf("%d", &chute);

    printf("Voce chutou o numero %d\n", chute);
    // no meio da frase
    printf("O numero secreto e %d!", numerosecreto);
}