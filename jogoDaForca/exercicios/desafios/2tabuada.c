//Desafio 2)
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int n;
    
    printf("Digite um numero: ");
    scanf("%d", &n);

    FILE *file;
    file = fopen("tabuada.txt", "w+");

    if(file == 0){
        printf("Erro no arquivo.\n");
        exit(1); 
    }

    for(int i = 1; i <= 20; i++){
        fprintf(file, "%d x %d = %d\n", n, i, i * n);
    }

    fclose(file);

    printf("Arquivo tabuada.txt craido.");

    return 0;
}