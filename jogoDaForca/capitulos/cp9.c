// Baseado no livro 'Introdução à programação em C: 
// Os primeiros passos de um desenvolvedor' de Maurício Aniche 

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]){
    int acertou = 0;
    int enforcou = 0;
    int tentativas = 0;
    char palavraSecreta[20];
    char chutes[27];
    // char palavraSecreta[0] = 'M'; //obrigatório as aspas simples para caracteres
    // char palavrasecreta[1] = 'E';
    // char palavrasecreta[2] = 'L';
    // char palavrasecreta[3] = 'A';
    // char palavrasecreta[4] = 'N';
    // char palavrasecreta[5] = 'C';
    // char palavrasecreta[6] = 'I';
    // char palavrasecreta[7] = 'A';
    // char palavrasecreta[8] = '\0';
    // printf("%s", palavraSecreta);
    sprintf(palavraSecreta, "MELANCIA"); //copia a palavra para o array/string

    printf("A palavra tem %d letras.\n", strlen(palavraSecreta));

    do{ //executa ao menos uma vez
        char chute;

        printf("Qual a letra? ");
        scanf(" %c", &chute); //o enter é considerado um caractere!
        //o espaço antes de %c ajuda a ignorar o enter

        chutes[tentativas] = chute;
        tentativas++;

        // for(int i = 0; i < strlen(palavraSecreta); i++){
        //     if(palavraSecreta[i] == chute){
        //         printf("A posicao %d tem essa letra.\n", i + 1);
        //     }
        // }

        for(int i = 0; i < strlen(palavraSecreta); i++){

            int achou = 0;

            for(int j = 0; j < tentativas; j++){
                if(chutes[j] == palavraSecreta[i]){
                    achou = 1;
                    break;
                }
            }

            if(achou){
                printf("%c ", palavraSecreta[i]);
            }else{
                printf("_ ");
            }
        }
        printf("\n");

    }while(!acertou && !enforcou);
    
    return 0;
}
