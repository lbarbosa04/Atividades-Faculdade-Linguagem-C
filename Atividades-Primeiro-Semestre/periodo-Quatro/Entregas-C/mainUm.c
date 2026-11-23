/*Desenvolver um software que vai permitir cadastrar livros e salvar em um arquivo (nome, autor e quantidade de pagin-
nas). O software deve permitir cadastrar inumeros livros, ate você dizer que não quer mais cadastar*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char nome[100];
char autor[100];
int paginas;
} Livro;

void limparBuffer() {
int c;
while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
FILE *arquivo;
Livro livro;
char continuar;

// Abre o arquivo em modo "a" (append) para adicionar novos livros sem apagar os anteriores
arquivo = fopen("C:\\Users\\Adm\\Desktop\\Salvar\\livros.txt", "a");

if (arquivo == NULL) {
printf("Erro ao abrir ou criar o arquivo!\n");
return 1;
}

printf("=== CADASTRO DE LIVROS ===\n");

do {
printf("\nNome do livro: ");
fgets(livro.nome, sizeof(livro.nome), stdin);
livro.nome[strcspn(livro.nome, "\n")] = '\0'; // Remove a quebra de linha do fgets

printf("Autor: ");
fgets(livro.autor, sizeof(livro.autor), stdin);
livro.autor[strcspn(livro.autor, "\n")] = '\0';

printf("Quantidade de paginas: ");
scanf("%d", &livro.paginas);
limparBuffer(); // Limpa o '\n' deixado pelo scanf

// Salva os dados formatados no arquivo
fprintf(arquivo, "Livro: %s | Autor: %s | Paginas: %d\n", livro.nome, livro.autor, livro.paginas);
fflush(arquivo); // Garante que os dados sejam gravados imediatamente no disco

printf("Livro salvo com sucesso!\n");

printf("\nDeseja cadastrar outro livro? (s/n): ");
scanf(" %c", &continuar);
limparBuffer();

} while (continuar == 's' || continuar == 'S');

fclose(arquivo);
printf("\nCadastro encerrado. Todos os livros foram salvos em 'livros.txt'.\n");

return 0;
}