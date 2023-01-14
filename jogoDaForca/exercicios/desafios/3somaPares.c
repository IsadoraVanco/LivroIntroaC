//Desafio 3)
#include <stdio.h>

int main(int argc, char const *argv[]){
    int a, n, soma = 0;
    
    printf("Quantos numeros serao lidos? \n");
    scanf("%d", &n);

    printf("Lendo numeros...\n");

    for(int i = 1; i <= n; i++){
        scanf("%d", &a);
        if(a & 2 == 0){
            soma += a;
        }
    }

    printf("A soma dos numeros pares eh %d.", soma);

    return 0;
}