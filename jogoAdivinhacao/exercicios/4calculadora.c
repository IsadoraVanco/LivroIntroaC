//Desafio 4)
#include <stdio.h>

int main(int argc, char const *argv[]){
    int a, b, operacao;
    printf("Digite um numero: ");
    scanf("%d", &a);
    printf("Agora outro: ");
    scanf("%d", &b);
    printf("**************************************************\n");
    printf("[1]SOMA [2]SUBTRACAO [3]MULTIPLICACAO [4]DIVISAO\n");
    printf("Selecione a operacao entre eles: ");
    scanf("%d", &operacao);

    printf("\n");
    switch(operacao){
        case 1:
            printf("%d + %d = %d\n", a, b, a + b);
            break;
        case 2:
            printf("%d - %d = %d\n", a, b, a - b);
            break;
        case 3:
            printf("%d * %d = %d\n", a, b, a * b);
            break;
        case 4:
            printf("%d / %d = %.2f\n", a, b, (float) a / b);
            break;
        default:
            printf("Operacao invalida.\n");
            break;
    }

    return 0;
}