// Baseado no livro 'Introdução a C' de Mauricio Ariche 
#include <stdio.h> 

int main(){ 
    int numerosecreto = 42;
    int chute;
    int pontos = 1000;
    int tentativas = 1;

    printf("************************************\n");
    printf("* Bem vindo ao Jogo da Adivinhacao *\n");
    printf("************************************\n");

    while(1){
        printf("Qual e o seu %do chute? ", tentativas);
        scanf("%d", &chute);

        if(chute < 0){
            printf("Voce nao pode chutar numeros negativos.\n");
            continue;
        }

        printf("Seu %do chute foi %d\n", tentativas, chute);
        
        int acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;
    
        if(acertou) {
           printf("Parabens! Voce acertou!\n");
           break;
        }else if(maior){
            printf("Seu chute foi maior do que o numero secreto!\n");
            
        }else{
            printf("Seu chute foi menor do que o numero secreto!\n");
        }

        tentativas++;
    }
}