// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main(){ 
    printf("************************************\n");
    printf("* Bem vindo ao Jogo da Adivinhacao *\n");
    printf("************************************\n");

    int chute, maior;
    int acertou = 0;
    int tentativas = 1;
    double pontosperdidos;
    double pontos = 1000;

    srand(time(0)); //define a "semente" para a função randomica, ou seja, como se fosse uma 
    //"fórmula" diferente para cada jogo, fazendo ser o mais randomico possivel.
    int numerosecreto = rand() % 100; //sorteia um numero deixa no intervalo de 0 a 99

    while(!acertou){
        printf("Qual e o seu %do chute? ", tentativas);
        scanf("%d", &chute);

        if(chute < 0){
            printf("Voce nao pode chutar numeros negativos.\n");
            continue;
        }

        printf("Seu %do chute foi %d\n", tentativas, chute);
        
        acertou = chute == numerosecreto;
        maior = chute > numerosecreto;
    
        if(acertou) {
           printf("Parabens! Voce acertou!\n");
        }else if(maior){
            printf("Seu chute foi maior do que o numero secreto!\n");
        }else{
            printf("Seu chute foi menor do que o numero secreto!\n");
        }

        tentativas++;
        pontosperdidos = abs((chute - numerosecreto)) / 2.0;
        pontos = pontos - pontosperdidos;
    }

    printf("Voce fez %.2lf pontos.\n", pontos);
    printf("Obrigada por jogar! ;)\n");
}