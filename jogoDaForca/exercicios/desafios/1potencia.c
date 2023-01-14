//Desafio 1)
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]){
    int a, b, n;
    
    printf("Digite dois numeros: \n");
    scanf("%d %d", &a, &b);

    n = powf(a, b);
    printf("%d ^ %d = %d\n", a, b, n);
    n = powf(b, a);
    printf("%d ^ %d = %d\n", b, a, n);

    return 0;
}