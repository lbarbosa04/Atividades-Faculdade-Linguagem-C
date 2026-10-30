/* Atividades 2 - Funções

objetivo

Praticar a criação e o uso de funções em C, separando o programa em partes menores:
Leitura, Cálculo, Conatgem e exibição

orientações:

- Faça todas as questões em linguagem C
- Sempre que a questão pedir função, não resolva tudo dentro da main
- Use nomes claros para as funções
- Quando houver quantidade fica de elementos, use #define
- Quando usar vetor, pecorra os elementos com for.
*/

/* 1 = Crie uma função que receba dois números inteiros e retonr o maior deles*/
#include <stdio.h>

#define MAX 2

int numeroMaior(int numero[MAX]){

    int maior = 0;
    
    for(int x = 0; x < MAX; x ++){
        printf("Digite um numero: ");
        scanf("%d", &numero[x]);
        if(numero[x] > maior){
            maior = numero[x];
        }
    }
    return maior;
}

int main()
{
    int numero;
    
    int maior = numeroMaior(numero);
    printf("Numero maior: %d", maior);
    
    return 0;
}

/* 2 = Crie uma função que receba um vetor de 10 números inteiros e exiba todos os elementos do vetor
No main, preencha o vetor com os números pares de 2 a 20 e chama a função para imprimir o vetor */

#include <stdio.h>

#define MAX 10

void numeroPar(int numero[MAX]){
    
    int i = 0;

    for(int x = 2; x <= 20; x ++){
        if(x % 2 == 0){
        numero[i] = x;
        i ++;
        }
    }
}

void printar(int numero[MAX]){
    
    for(int x = 0; x < 10; x ++){
        printf("\nNumero: %d", numero[x]);
    }
}

int main()
{
    int numero[MAX]; 
    numeroPar(numero);
    printar(numero);

    return 0;
}

/* 3 = Crie uma função que receba um vetor com 5 números inteiros e retorne a soma dos elementos*/

#include <stdio.h>

#define MAX 5

int somaVetor(int numero[MAX]){
    
    int soma = 0;
    
    for(int x = 0; x < 5; x ++){
        printf("Digite o numero: ");
        scanf("%d", &numero[x]);
        soma += numero[x];
    }
    
    return soma;
    
}

int main()
{
    int numero[MAX]; 
    int resultado = somaVetor(numero);
    printf("Soma: %d", resultado);

    return 0;
}

/* 4 = Crie uma função que receba um vetor de 10 números inteiros e retorne o menor elemento do vetor*/

#include <stdio.h>

#define MAX 10

int menor(int numero[MAX]){
    
    int menorNumero;
    
    for(int x = 0; x < 10; x ++){
        printf("Digite o numero: ");
        scanf("%d", &numero[x]);
        
        if(x == 0 || numero[x] < menorNumero){
            menorNumero = numero[x];
        }
        
    }
    return menorNumero;
}

int main()
{
    int numero[MAX]; 
    int resultado = menor(numero);
    printf("Menor Número: %d", resultado);

    return 0;
}
