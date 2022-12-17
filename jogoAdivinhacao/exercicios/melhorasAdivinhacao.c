// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

//Exercícios:
//1) Deixe o usuário escolher o mínimo e máximo do número sorteado
//2) Use defines para as quantidades de tentativas em cada nível
//3) Ao terminar o jogo, pergunte se o usuário quer jogar novamente, em caso afirmativo, ele digita '1'
//4) Não deixe o usuário jogar o mesmo número na sequência

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define PONTOS_INICIAL 100
#define TENTATIVAS_FACIL 20
#define TENTATIVAS_MEDIO 10
#define TENTATIVAS_DIFICIL 5
#define MINIMO_INTERVALO 9

int main(){ 
    int nivel, tentativas, numeroMaximo, numeroMinimo;
    int maior, chute, chuteAnterior, numeroSecreto;
    int acertou = 0;
    int querJogar = 1;
    double pontosperdidos;
    double pontos = PONTOS_INICIAL;

    printf("\n\n");
    printf("       P  /_\\  P                                \n"); 
    printf("      /_\\_|_|_/_\\                              \n"); 
    printf("  n_n | ||. .|| | n_n           Bem-vind@ ao     \n");
    printf("  |_|_|nnnn nnnn|_|_|       Jogo de Adivinhacao! \n");
    printf(" | \" \" |  |_|  | \" \" |                       \n"); 
    printf(" |_____| ' _ ' |_____|                           \n");
    printf("       \\__|_|__/                                \n");
    printf("\n\n");
    
    while(querJogar){
        printf("Escolha o numero minimo para palpite: ");
        scanf("%d", &numeroMinimo);
        printf("Agora o numero maximo: ");
        scanf("%d", &numeroMaximo);
        
        while(numeroMaximo < numeroMinimo + MINIMO_INTERVALO){
            printf("O numero maximo precisa ser no minimo %d!\n", numeroMinimo + MINIMO_INTERVALO);
            printf("Agora o numero maximo: ");
            scanf("%d", &numeroMaximo);
        }

        printf("\nQual o nivel de dificuldade?\n");
        printf("[1] Facil [2] Medio [3] Dificil\n\n");
        printf("Escolha: ");
        scanf("%d", &nivel);

        srand(time(0)); 
        numeroSecreto = rand() % numeroMaximo; 

        while(numeroSecreto < numeroMinimo || numeroSecreto > numeroMaximo){
            numeroSecreto = rand() % numeroMaximo; 
        }
        
        switch(nivel){
            case 1:
                tentativas = TENTATIVAS_FACIL;
                printf("...Nivel FACIL...\n");
                break;
            case 2:
                tentativas = TENTATIVAS_MEDIO;
                printf("...Nivel MEDIO...\n");
                break;
            default:
                tentativas = TENTATIVAS_DIFICIL;
                printf("...Nivel DIFICIL...\n");
                break;
        }

        for(int i = 1; i <= tentativas; i++){
            printf("=>Tentativa %d de %d: ", i, tentativas);
            scanf("%d", &chute);

            if(chute < numeroMinimo || chute > numeroMaximo){
                printf("Chute numeros entre %d e %d.\n\n", numeroMinimo, numeroMaximo);
                i--;
                continue;
            }else if(i > 1 && chuteAnterior == chute){
                printf("Voce chutou o numero %d antes!\n\n", chuteAnterior);
                i--;
                continue;
            }
            
            acertou = chute == numeroSecreto;
            maior = chute > numeroSecreto;
        
            if(acertou) {
                break;
            }else if(maior){
                printf("Seu chute foi MAIOR do que o numero secreto!\n\n");
            }else{
                printf("Seu chute foi MENOR do que o numero secreto!\n\n");
            }

            pontosperdidos = abs((chute - numeroSecreto)) / 2.0;
            pontos = pontos - pontosperdidos;
            chuteAnterior = chute;
        }

        if(acertou) {
            printf("\n");
            printf("              OOOOOOOOOOO \n");
            printf("          OOOOOOOOOOOOOOOOOOO \n");
            printf("       OOOOOO  OOOOOOOOO  OOOOOO \n");
            printf("     OOOOOO      OOOOO      OOOOOO \n");
            printf("   OOOOOOOO   #  OOOOO   #  OOOOOOOO \n");
            printf("  OOOOOOOOOO    OOOOOOO    OOOOOOOOOO \n");
            printf(" OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO \n");
            printf(" OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO \n");
            printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO \n");
            printf("  OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO \n");
            printf("   OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO \n");
            printf("     OOOOO   OOOOOOOOOOOOOOO   OOOO \n");
            printf("       OOOOOO   OOOOOOOOO   OOOOOO \n");
            printf("          OOOOOO         OOOOOO \n");
            printf("              OOOOOOOOOOOO \n");

            printf("\nParabens! Voce acertou!\n");
            printf("=========TOTAL DE %.2lf PONTOS=========\n", pontos);
        }else{
            printf("       \\|/ ____ \\|/        \n");
            printf("        @~/ ,. \\~@          \n");
            printf("       /_( \\__/ )_\\        \n");
            printf("          \\__U_/            \n");
            printf("\nVoce perdeu! Tente novamente!\n");
        }

        printf("=>> Quer jogar novamente? <<=\n");
        printf("        [1]Sim  [0]Nao\n\n");
        printf("Escolha: ");
        scanf("%d", &querJogar);

        while(querJogar != 0 && querJogar != 1){
            printf("Opcao impossivel! Digite 1 para jogar novamente, ou 0 para finalizar.\n");
            printf("Escolha: ");
            scanf("%d", &querJogar);
        }

        switch(querJogar){
            case 0:
                printf("Obrigada por jogar! :)\n");
                break;
            case 1:
                printf("Ok, vamos la! :)\n");
                printf("***************************************\n\n");
                break;
        }
    }
}