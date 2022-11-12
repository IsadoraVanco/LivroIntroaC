// Baseado no livro 'Introdução a C' de Mauricio Ariche 
#include <stdio.h> 
//é por convenção, que usamos letras maiusculas e underscore para nomear constantes em C
#define NUMERO_DE_TENTATIVAS 3

int main(){ 
    int numerosecreto;
    int chute;

    printf("************************************\n");
    printf("* Bem vindo ao Jogo da Adivinhacao *\n");
    printf("************************************\n");

    numerosecreto = 42;
    for(int i = 1; i <= NUMERO_DE_TENTATIVAS; i++){
        printf("Qual e o seu chute? ");
        scanf("%d", &chute);

        if(chute < 0){
            printf("Voce nao pode chutar numeros negativos.\n");
            i--;
            //passa para a proxima iteração do loop, ignora o resto do codigo seguinte
            //o mesmo efeito aconteceria com o if-else, mas o continue permite que o codigo
            //fique mais limpo e facil de ser lido
            continue;
        }

        printf("Seu chute foi %d\n", chute);
        //o C não possui uma variavel booleana, por isso, 
        //quando for verdade, acertou recebe 1 e quando for falsa, recebe 0
        int acertou = chute == numerosecreto;
    
        if(acertou) {
            printf("Parabens! Voce acertou!\n");
            break;
            //printf("Jogue de novo, você é um bom jogador!\n");
        } else {
            printf("Voce errou!\n");
            int maior = chute > numerosecreto;
            int menor = chute < numerosecreto;
            if(maior) {
                printf("Seu %do chute foi maior do que o numero secreto!\n", i);
            }else if(menor){
                printf("Seu %do chute foi menor do que o numero secreto!\n", i);
            }
            // printf("Mas não desanime, tente de novo!\n");
        }

    }

    printf("O numero secreto e %d!", numerosecreto);
}