//Desafio 1)
#include <stdio.h>

int main(int argc, char const *argv[]){
    printf("NUMEROS PARES ENTRE 2 E 50:\n");

    for(int i = 2; i <= 50; i+=2){
        printf("=> %d \n", i);
    }

    return 0;
}