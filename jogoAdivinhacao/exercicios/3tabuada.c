//Desafio 3)
#include <stdio.h>

int main(int argc, char const *argv[]){
    int n;
    printf("Digite um numero para calcular a sua tabuada: ");
    scanf("%d", &n);

    for(int i = 1; i <= 10; i++){
        printf("%d x %d = %d \n", n, i, n * i);
    }

    return 0;
}