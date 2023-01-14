//Desafio 6)
#include <stdio.h>

#define TAMANHO 5

void apagaArray(int* array, int tamanho);

int main(int argc, char const *argv[]){
    int array[TAMANHO] = {1, 2, 3, 4, 5};
    
    printf("Array inicial: \n");
    for(int i = 0; i < TAMANHO; i++){
        printf("%d ", array[i]);
    }

    apagaArray(array, TAMANHO);

    printf("\nArray final: \n");
    for(int i = 0; i < TAMANHO; i++){
        printf("%d ", array[i]);
    }

    return 0;
}

void apagaArray(int* array, int tamanho){
    for(int i = 0; i < tamanho; i++){
        *(array)++ = 0;
    }
}