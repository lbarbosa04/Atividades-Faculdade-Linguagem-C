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

int numeroMaior(int valorUm, int valorDois){
    
    int numero[MAX];
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
    
    int maior = numeroMaior(1 , 2);
    printf("Numero maior: %d", maior);
    
    return 0;
}