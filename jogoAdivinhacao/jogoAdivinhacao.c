// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main(){ 
    int chute, maior, nivel, tentativas;
    int acertou = 0;
    double pontosperdidos;
    double pontos = 1000;

    srand(time(0)); 
    int numerosecreto = rand() % 100; 

    printf("\n\n");
    printf("       P  /_\\  P                                \n"); 
    printf("      /_\\_|_|_/_\\                              \n"); 
    printf("  n_n | ||. .|| | n_n         Bem-vind@ ao       \n");
    printf("  |_|_|nnnn nnnn|_|_|       Jogo de Adivinhacao! \n");
    printf(" | \" \" |  |_|  | \" \" |                       \n"); 
    printf(" |_____| ' _ ' |_____|                           \n");
    printf("       \\__|_|__/                                \n");
    printf("\n\n");

    printf("Qual o nivel de dificuldade?\n");
    printf("[1] Facil [2] Medio [3] Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch(nivel){
        case 1:
            tentativas = 20;
            printf("...Nivel FACIL...\n");
            break;
        case 2:
            tentativas = 10;
            printf("...Nivel MEDIO...\n");
            break;
        default:
            tentativas = 5;
            printf("...Nivel DIFICIL...\n");
            break;
    }

    for(int i = 1; i <= tentativas; i++){
        printf("=>Tentativa %d de %d: ", i, tentativas);
        scanf("%d", &chute);

        if(chute < 0){
            printf("Voce nao pode chutar numeros negativos.\n");
            i--;
            continue;
        }
        
        acertou = chute == numerosecreto;
        maior = chute > numerosecreto;
    
        if(acertou) {
           break;
        }else if(maior){
            printf("Seu chute foi maior do que o numero secreto!\n\n");
        }else{
            printf("Seu chute foi menor do que o numero secreto!\n\n");
        }

        pontosperdidos = abs((chute - numerosecreto)) / 2.0;
        pontos = pontos - pontosperdidos;
    }

    if(acertou) {
        printf("\n");
        printf("              OOOOOOOOOOO              \n");
        printf("          OOOOOOOOOOOOOOOOOOO          \n");
        printf("       OOOOOO  OOOOOOOOO  OOOOOO       \n");
        printf("     OOOOOO      OOOOO      OOOOOO     \n");
        printf("   OOOOOOOO   #  OOOOO   #  OOOOOOOO   \n");
        printf("  OOOOOOOOOO    OOOOOOO    OOOOOOOOOO  \n");
        printf(" OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO \n");
        printf(" OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO \n");
        printf("  OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf("   OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("     OOOOO   OOOOOOOOOOOOOOO   OOOO    \n");
        printf("       OOOOOO   OOOOOOOOO   OOOOOO     \n");
        printf("          OOOOOO         OOOOOO        \n");
        printf("              OOOOOOOOOOOO             \n");

        printf("\nParabens! Voce acertou!\n");
        printf("Voce fez %.2lf pontos. Ate a proxima!\n", pontos);
    }else{
        printf("       \\|/ ____ \\|/        \n");
        printf("        @~/ ,. \\~@          \n");
        printf("       /_( \\__/ )_\\        \n");
        printf("          \\__U_/            \n");
        printf("Voce perdeu! Tente novamente!\n");
    }
}