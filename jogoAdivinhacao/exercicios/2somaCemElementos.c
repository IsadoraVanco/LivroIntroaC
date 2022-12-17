//Desafio 2)
#include <stdio.h>

int main(int argc, char const *argv[]){
    int soma = 0;
    printf("A soma de todos os elementos entre 1 e 100 eh: ");

    for(int i = 1; i <= 100; i++){
        soma += i;
    }
    printf("%d ;)\n", soma);

    return 0;
}
