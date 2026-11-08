//Lista de exercicios - Structs em linguagem C

/* 1 = Cadastro de pessoas
Implemente um programa que leia o nome a idade e o endereço de uma pessoa e armazene os dados em uma estrutura*/
#include <stdio.h>

#define MAX_CADASTRO 10

typedef struct enderecos {
    char cidade[15];
    char bairro[20];
    char logradouro[30];
    int numero;
} endereco;

typedef struct pessoas {
    endereco enderecos;
    
    char nome[30];
    int idade;

} pessoa;

int main()
{
    pessoa pessoas[MAX_CADASTRO];
    int posicao = 1;
    
    for(int x = 1; x <= MAX_CADASTRO; x ++ ){
        printf("cadastro nº: %d\n", posicao);
        printf("Digite seu nome: ");
        scanf(" %49[^\n]", &pessoas[x].nome);
        printf("Digite sua idade: ");
        scanf("%d", &pessoas[x].idade);
        printf("Digite o nome da sua cidade: ");
        scanf(" %49[^\n]", &pessoas[x].enderecos.cidade);
        printf("Digite o nome do seu bairro: ");
        scanf(" %49[^\n]", &pessoas[x].enderecos.bairro);
        printf("Digite o nome do seu logradouro: ");
        scanf(" %49[^\n]", &pessoas[x].enderecos.logradouro);
        printf("Digite o numero da sua casa: ");
        scanf("%d", &pessoas[x].enderecos.numero);
        posicao ++;
        
    }
    
    return 0;
}


/*2 = Cadastro alunos
Construa uma estrutura de alunos com nome, número de matricula e nome do curso. Leia do usúario a informação de 5 alunos, armazene em um vetor essa estrutura e imprima os dados na tela*/
#include <stdio.h>

#define MAX_CADASTRO 5
#define MAX_NOTAS 4

typedef struct alunos {
    
    char nome[30];
    int matricula;
    char curso[20];

} aluno;

int main()
{
    aluno alunos[MAX_CADASTRO];
    int posicao = 1;
    
    for(int x = 0; x < MAX_CADASTRO; x ++ ){
        printf("cadastro nº: %d\n", posicao);
        printf("Digite seu nome: ");
        scanf(" %49[^\n]", &alunos[x].nome);
        printf("Nome do curso: ");
        scanf(" %49[^\n]", &alunos[x].curso);
        alunos[x].matricula = posicao;

        posicao ++;
        
    }
    
    for(int a = 0; a < MAX_CADASTRO; a ++ ){
        printf("Matricula: %d\n", alunos[a].matricula);
        printf("Aluno: %s\n", alunos[a].nome);
        printf("curso: %s\n", alunos[a].curso);
    }
    
    return 0;
}

/*3 = sistema de notas dos alunos
Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve conter a matricula do aluno, nome nota da
primeira provas, segunda e terceira.
a = Permita ao usuario entrar com os dados de 5 alunos
b = Encontre o aluno com a maior nota da primeira prova
c = Encontre o aluno com a maior media geral
d = Encontre o aluno com a menor media geral
e = Para cada aluno diga se ele foi aprovado ou reprovado
*/

#include <stdio.h>

#define MAX_CADASTRO 2
#define MAX_NOTAS 3

typedef struct alunos {
    char nome[30];
    char curso[20];
    float nota[MAX_NOTAS];
    float somaNotas = 0;
} aluno;

int main()
{
    aluno alunos[MAX_CADASTRO];
    float maiorNota = 0;
    int indiceMaior = 0;

    for (int x = 0; x < MAX_CADASTRO; x++) {
        printf("\n--- Aluno %d ---\n", x + 1);

        printf("Nome do aluno: ");
        scanf(" %29[^\n]", alunos[x].nome);

        printf("Nome do curso: ");
        scanf(" %19[^\n]", alunos[x].curso);

        for (int a = 0; a < MAX_NOTAS; a++) {
            printf("Digite a nota %d: ", a + 1);
            scanf("%f", &alunos[x].nota[a]);
            somaNotas += alunos[x].notas[a];
        }

        if (x == 0 || alunos[x].nota[0] > maiorNota) {
            maiorNota = alunos[x].nota[0];
            indiceMaior = x;
        }
        
    }

    printf("\nMaior nota na primeira prova: %.2f\n", maiorNota);
    printf("Aluno: %s\n", alunos[indiceMaior].nome);
    printf("Curso: %s\n", alunos[indiceMaior].curso);

    return 0;
}