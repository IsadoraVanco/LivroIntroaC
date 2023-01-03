//Desafio 5)
#include <stdio.h>

int main(int argc, char const *argv[]){
    int a, b, menor, maior, soma = 0;
    
    printf("Digite dois numeros: \n");
    scanf("%d %d", &a, &b);

    if(a >= b){
        maior = a;
        menor = b;
    }else{
        maior = b;
        menor = a;
    }

    for(int i = menor + 1; i < maior; i++){
        int ehPrimo = 1;
        int n = i;
        
        if(n < 0){
            n *= -1;
        }else if(n == 0){
            ehPrimo = 0;
        }

        for(int j = 2; j <= n; j++){
            if(n % j == 0 && n != j){
                ehPrimo = 0;
                break;
            }
        }

        if(!ehPrimo){
            continue;
        }

        soma += i;
    }

    printf("A soma dos primos entre %d e %d eh %d.", a, b, soma);

    return 0;
}