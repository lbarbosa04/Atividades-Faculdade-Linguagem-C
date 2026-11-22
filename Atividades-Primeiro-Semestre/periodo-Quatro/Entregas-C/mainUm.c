/*Desenvolver um software que vai permitir cadastrar livros e salvar em um arquivo (nome, autor e quantidade de pagin-
nas). O software deve permitir cadastrar inumeros livros, ate você dizer que não quer mais cadastar*/
#include <stdio.h>
#include <string.h>

int main(){
    
    FILE *arquivo;
    int opcao;

    arquivo = fopen("C:\\Users\\Adm\\Desktop\\Salvar\\teste.txt", "w");
    fprintf(arquivo, "O gato de botas");
    fclose(arquivo);

    

    return 0;
}



//C:\\Users\\Adm\\Desktop\\Salvar\\teste.txt

/*
    do {

    printf("Deseja continuar o cadastro dos livros ?\n1 - Sim\n2 - Não");
    scanf("%d", &opcao);
    } while (opcao == 2);
*/