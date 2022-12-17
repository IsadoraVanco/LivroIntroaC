//Desafio 5)
#include <stdio.h>

int main(int argc, char const *argv[]){
    int n, fatorial = 1;
    printf("Digite um numero para calcular seu fatorial: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        fatorial *= i;
    }
    printf("%d! = %d\n", n, fatorial);

    return 0;
}