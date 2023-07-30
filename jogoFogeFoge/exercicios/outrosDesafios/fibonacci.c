// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

//Desafio:
/*
1) Desenhe a árvore de invocação para fib(5). Você percebeu algo problemático?
2) Faça a função de fib(5) não precisar recalcular os mesmos valores mais
    de uma vez. Para isso, use um array para guardar os valores já calculados.
    Essa técnica é conhecida como memorização.
*/
#include <stdio.h>

int inicializaVetor(int vetor[], int tamanhoVetor){
    for(int i = 0; i < tamanhoVetor; i++){
        vetor[i] = -1;
    }
}

int fibonacci(int n, int vetor[]){

    if(vetor[n - 1] != -1){
        return vetor[n - 1];
    }

    if(n == 1){
        vetor[n - 1] = 0;
    }else if(n == 2){
        vetor[n - 1] =  1;
    }else{
        vetor[n - 1] = fibonacci(n - 1, vetor) + fibonacci(n - 2, vetor);
    }

    return vetor[n - 1];
}

int main(int argc, char const *argv[]){
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);

    int termos[n];
    inicializaVetor(termos, n);

    printf("O %dº termo da sequência de Fibonacci é %d\n", n, fibonacci(n, termos));
    
    return 0;
}
