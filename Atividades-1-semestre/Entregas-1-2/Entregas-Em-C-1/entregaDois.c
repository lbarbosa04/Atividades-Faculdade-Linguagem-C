// 1 = Preencha um vetor com os números pares do número 2 a 20 e imprima o vetor na tela
#include <stdio.h>

int main()
{
    int vetor[10];
    int x, j=0, z;
    
    for(x = 2; x <= 20; x += 1){ //loop
        if(x % 2 == 0){ //Essa condição é para atribuir ao vetor os números pares
          vetor[j] = x;
          j+=1;
        }
    }
    
    for(z = 0; z < j; z += 1){ //Utilizo o loop para printar os números
        printf("\n%d", vetor[z]);
    }

    return 0;
}


/* 2 = Preencha um primeiro vetor com o quadro dos números pares do intervaldo de 2 a 20. Preencher um 
segundo vetor com os números de 10 a 19. mostrar a soma dos dois vetores.
*/ 
#include <stdio.h>

int main()
{
    int vetorUm[10];
    int vetorDois[10];
    int soma=0;
    int x, j=0, z=0;
    
    for(x = 2; x <= 20; x += 1){ //loop
        if(x % 2 == 0){
          vetorUm[j] = x * x; //Calculo utilizado para atribuir ao vetor o número ao quadrado
          j+=1;
        }
   }
    
     j = 0; //Linha utilizada para excluir na memorio os valores de J que foi atribuido no primeiro loop
     
     for(x = 10; x <= 19; x += 1){ 
         vetorDois[j] = x; 
         j += 1;
   }
    
     for(x = 0; x < 10; x += 1){ //Loop utilizado para somar os dois vetores
         for(j = 0; j < 10; j += 1){
             soma += vetorUm[x] + vetorDois[j]; 
             z += 1;
         }
   }
     
    printf("soma = %d\n", soma);
    
    return 0;
}


/* 3 = Leia 10 números inteiros informados pelo usuário e armazenado em um vetor. 
Em seguida determine e imprima o menor elemento no vetor.
*/ 
#include <stdio.h>

int main()
{
    int vetor[10];
    int menorNumero;
    int x, j=0;
    
    for(x = 0; x < 10; x += 1){
        printf("Digite um número: ");
        scanf("%d", &vetor[x]);
        
        //If utilizado para inciar o x em 0 e achar o menor nuemro desse vetor 
        if(x == 0 || vetor[x] < menorNumero){
            menorNumero = vetor[x];    //MenorNumero recebe o x, sempre que o proximo número for menor que o anterior
        }                              //ele faz a troca  
        
        j += 1;
    }
    
    printf("Menor numero: %d", menorNumero);
     
    
    return 0;
}


/* 4 = Preencher um vetor com 5 números inteiros, solicitar um número do teclado. Pesquisar se esse número existe
no vetor. Se existir, imprimir em qual posição do vetor, se não existir, imprimir mensagem informando que não existe.
*/
#include <stdio.h>

int main()
{
    int vetor[5];
    int numeroDigitado;
    int x, j=0;
    
    for(x = 0; x < 5; x += 1){
        printf("Digite um número: ");
        scanf("%d", &vetor[x]);
    }
    
    printf("Digite um número para comparar com os salvos: ");
    scanf("%d", &numeroDigitado);
    
    for(x = 0; x < 5; x += 1){
        if(numeroDigitado == vetor[x]){ //Loop utilizado para comparar os número do vetor com o digitado
        printf("Numero: %d\n Posição: %d", numeroDigitado, x);
        j += 1;
      } 
    }
    
    if (j == 0) {
        printf("Numero nao existe!\n");
    }
    
    return 0;
}


/* 5 = Gerar/criar um vetor de 10 posições, randomicamente, depois ler um valor e verificar se esse valor
está ou não no vetor gerado;
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[10];
    int numeroDigitado;
    int x, j = 0;
 
    for (x = 0; x < 10; x++) { // Gera 10 números aleatórios entre 1 e 20
        vetor[x] = rand() % 20 + 1;
    }

    printf("Vetor gerado: ");  // Mostra o vetor gerado (útil para conferir o resultado)
    for (x = 0; x < 10; x++) {
        printf("%d ", vetor[x]);
    }
    printf("\n");

    printf("Digite um numero para buscar: ");
    scanf("%d", &numeroDigitado);

    for (x = 0; x < 10; x++) { // Procura o número no vetor
        if (numeroDigitado == vetor[x]) {
            printf("Numero %d encontrado na posicao %d\n", numeroDigitado, x);
            j++;
        }
    }

    if (j == 0) {
        printf("Numero nao esta no vetor.\n");
    }

    return 0;
}


/* 6 = Gerar/criar um vetor de 10 posições, randomicamente, depois contar quantos pares, quantos impares e quantos
números primos existem no vetor;
*/
#include <stdio.h>
#include <stdlib.h>

int ehPrimo(int n) // Retorna 1 se n for primo, 0 caso contrario
{
    int d;

    if (n < 2) { // 0 e 1 nao sao primos
        return 0;          
    }

    for (d = 2; d * d <= n; d++) { // achou divisor, nao e primo
        if (n % d == 0) {
            return 0;      
        }
    }

    return 1;
}

int main()
{
    int vetor[10];
    int x;
    int pares = 0, impares = 0, primos = 0;
    
    for (x = 0; x < 10; x++) { // Gera 10 numeros aleatorios entre 1 e 50
        vetor[x] = rand() % 50 + 1;
    }
  
    printf("Vetor gerado: "); // Mostra o vetor
    for (x = 0; x < 10; x++) {
        printf("%d ", vetor[x]);
    }
    printf("\n");

    for (x = 0; x < 10; x++) { // Conta pares, impares e primos
        if (vetor[x] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }

        if (ehPrimo(vetor[x])) {
            primos++;
        }
    }

    printf("Pares: %d\n", pares);
    printf("Impares: %d\n", impares);
    printf("Primos: %d\n", primos);

    return 0;
}


/* 7 = Gerar/criar um vetor de 10 posições, randomicamente, depois contar quantos valores repetiods
existem no vetor gerado; 
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[10];
    int x, j;
    int valoresRepetidos = 0;   // numeros diferentes que aparecem 2+ vezes
    int repeticoesExtras = 0;   // posicoes que repetem um valor anterior

    for (x = 0; x < 10; x++) {  // Gera 10 numeros aleatorios entre 1 e 15
        vetor[x] = rand() % 15 + 1;
    }

    printf("Vetor gerado: ");  // Mostra o vetor
    for (x = 0; x < 10; x++) {
        printf("%d ", vetor[x]);
    }
    printf("\n");

    for (x = 0; x < 10; x++) {
        int jaApareceu = 0;     
        int total = 0;          

        for (j = 0; j < 10; j++) {
            if (vetor[j] == vetor[x]) {
                total++;
                if (j < x) {
                    jaApareceu = 1;
                }
            }
        }

        if (jaApareceu) {
            repeticoesExtras++;         // nao é a primeira ocorrencia
        } else if (total > 1) {
            valoresRepetidos++;         // primeira ocorrencia de um valor repetido
        }
    }

    printf("Valores diferentes que se repetem: %d\n", valoresRepetidos);
    printf("Repeticoes extras: %d\n", repeticoesExtras);

    return 0;
}


/* 8 = Crie um programa 10 números, armazene eles em um vetor e diga qual elemento é o maior, qual é o menor
e qual a média dos valores.
*/
#include <stdio.h>

int main()
{
    int vetor[10];
    int x;
    int maiorNumero, menorNumero;
    int soma = 0;
    double media;

    for (x = 0; x < 10; x++) {
        printf("Digite um numero: ");
        scanf("%d", &vetor[x]);

        soma += vetor[x];

        if (x == 0 || vetor[x] > maiorNumero) {
            maiorNumero = vetor[x];
        }

        if (x == 0 || vetor[x] < menorNumero) {
            menorNumero = vetor[x];
        }
    }

    media = soma / 10.0;

    printf("Maior: %d\n", maiorNumero);
    printf("Menor: %d\n", menorNumero);
    printf("Media: %.2f\n", media);

    return 0;
}


/* 9 = Faça um vetor que armazene as notas de 10 estudantes. Em seguida imprima as 5 melhores notas em
ordem crescente
*/
#include <stdio.h>

int main()
{
    float notas[10];
    float aux;
    int x, j;

    for (x = 0; x < 10; x++) {  // Leitura das notas
        printf("Digite a nota do aluno %d: ", x + 1);
        scanf("%f", &notas[x]);
    }
  
    for (x = 0; x < 9; x++) { // Ordenação para crescente
        for (j = 0; j < 9 - x; j++) {
            if (notas[j] > notas[j + 1]) {
                aux = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = aux;
            }
        }
    }

    printf("\nAs 5 melhores notas em ordem crescente:\n"); // As 5 melhores são as últimas 5 posições
    for (x = 5; x < 10; x++) {
        printf("%.1f\n", notas[x]);
    }

    return 0;
}


/* 10 = Escreva um programa que leia 20 notas de alunos de uma turma. O programa deve calcular a média da turma
e apresentar na tela apenas as notas dos alunos que ficaram acima da média calculada. 
*/
#include <stdio.h>

int main()
{
    float notas[20];
    float soma = 0, media;
    int x, acima = 0;

    for (x = 0; x < 20; x++) { // loop para leitura e soma
        printf("Digite a nota do aluno %d: ", x + 1);
        scanf("%f", &notas[x]);
        soma += notas[x];
    }

    media = soma / 20;

    printf("\nMedia da turma: %.2f\n", media);

    printf("Notas acima da media:\n"); // loop para mostra apenas as notas acima da média
    for (x = 0; x < 20; x++) {
        if (notas[x] > media) {
            printf("Aluno %d: %.1f\n", x + 1, notas[x]);
            acima++;
        }
    }

    if (acima == 0) {
        printf("Nenhuma nota ficou acima da media.\n");
    }

    return 0;
}