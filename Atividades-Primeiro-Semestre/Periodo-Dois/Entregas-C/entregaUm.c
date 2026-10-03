// 1 = Escreva um aplicativo em C mostra todos os números impares de 1 a 100
#include <stdio.h>

int main() {
   int x;

   for(x = 1; x <=100; x +=1){
        if(x % 2 == 0){
             printf("\nPar: %d", x);
        }
    }
}


// 2 = Leia um numero e verifique se ele é um número primo
#include <stdio.h>

int main() {
    int n, i, ePrimo = 1;

    printf("Digite um numero: ");
    scanf("%d", &n);

    if (n <= 1) {
        ePrimo = 0; 
    } else {
        for (i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                ePrimo = 0; 
                break;       
            }
        }
    }

    if (ePrimo) {
        printf("%d é primo.\n", n);
    } else {
        printf("%d não é primo.\n", n);
    }

    return 0;
}


// 3 = Escreva um programa que pergunta um número ao usuário, e mostra sua tabuada completa (de 1 até 10) 
#include <stdio.h>

int main() {
    int numero, x, j, y, z, resultado;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    for(x = 1; x <= 10; x+= 1){
        printf("\n%d + %d: %d ", numero, x, numero + x);
    }

    for(j = 1; j <= 10; j += 1){
        printf("\n%d - %d: %d ", numero, j, numero - j);
    }

    for(y = 1; y <= 10; y += 1){
        printf("\n%d * %d: %d ", numero, y, numero * y);
    }

    for(z = 1; z <= 10; z += 1){
        printf("\n%d / %d: %d ", numero, z, numero / z);
    }
}


/* 4 = Escreva um programa em C que solicita 10 números ao usuário, através de um laço while, e ao final mostre
qual destes números é o maior.
*/
#include <stdio.h>

int main() {
    int numero, i = 1, maior;

    printf("Digite um numero: ");
    scanf("%d", &numero);
    maior = numero;
    i++;

    while (i <= 10) {
        printf("Digite um numero: ");
        scanf("%d", &numero);

        if (numero > maior) {
            maior = numero;
        }

        i += 1;
    }

    printf("Numero maior: %d", maior);

    return 0;
}


// 5 = Escreva um programa em C que leia 10 números e escreva a diferença entre a maior e o menor valor dito.
#include <stdio.h>

int main() {

    int numero, maior, menor, i;

    for (i = 0; i < 10; i++) {
        printf("Digite um numero: ");
        scanf("%d", &numero);

        if (i == 0) {
           
            maior = numero;
            menor = numero;
        } else {
            if (numero > maior) {
                maior = numero;
            }
            if (numero < menor) {
                menor = numero;
            }
        }
    }

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
    printf("Diferenca: %d\n", maior - menor);

    return 0;
}


// 6 = Faça um programa que imprime todos os divisores de um número inteiro positivo.
#include <stdio.h>

int main() {
    int numero;

    printf("Digite um numero inteiro e positivo: ");
    scanf("%d", &numero);

    printf("Divisores de %d:\n", numero);

    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}