//Desafio 4)
#include <stdio.h>

int main(int argc, char const *argv[]){
    int n, ehPrimo = 1;
    
    printf("Digite um numero: \n");
    scanf("%d", &n);

    int nNegativo = n;

    if(n == 0){
        printf("%d nao pode ser primo.", n);
        return 0;
    }else if(n < 0){
        n *= -1;
    }

    for(int i = 2; i <= n - 1; i++){
        if(n % i == 0 && n != i){
            ehPrimo = 0;
            n = nNegativo;
            printf("%d nao eh primo.", n);
            break;
        }
    }

    if(ehPrimo){
        n = nNegativo;
        printf("%d eh primo.", n);
    }

    return 0;
}