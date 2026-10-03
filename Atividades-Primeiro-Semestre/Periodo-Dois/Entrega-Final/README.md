<h1 align="center">Entrega Final</h1>

## 🎯 Objetivo do Projeto
Desenvolver uma aplicação em Linguagem **C** para efetuar o registro de alunos e das respectivas notas finais, processar dados estatísticos da turma e permitir a consulta individal por nome. O projeto tem como finalidade consolidar os conceitos fundamentais de lógica de programação utilizando **exclusivamente estruturas condicionais (if/else), laços de repetição (FOR, WHILE, DO-WHILE) e VETORES (unidimensionais e paralelos para strings)

## 📌 Requisitos Técnicos e Escopo
O projeto deve cumprir rigorosamente as seguintes restrições técnicas:

**•Permitido:** Estruturas condicionais(IF/ELSE, SWITCH-CASE), laços de repetição (FOR, WHILE, DO-WHILE), vetores de tipos primitivos (FLOAT/INT) e vetores de caracteres/strings (char nomes[N][50]).

## 📌 Requisitos Funcionais
**3.1** **Estrutura de Dados (Vetores Paralelos)**

**•** char nomes[N][50]: Vetor de cadeias de caracteres para armazenar o nome de até
N alunos (ex: N = 10).

**•** float notas[N]: Vetor para armazenar a nota final correspondente de cada aluno.

**•** **Regra de Associação:** O aluno no índice i do vetor nomes é o proprietário da nota
presente no índice i do vetor notas.

**3.2** **Entrada de Dados e Validação**

**•** Permitir o registo sequencial do nome e da nota de cada aluno.

**•** Validar a nota introduzida através de laços de repetição (while ou do-while),

garantindo que apenas são aceites valores no intervalo entre 0.0 e 10.0.

**3.3** **Relatório Estatístico da Turma**

**•** Calcular e exibir a média geral de notas da turma.

**•** Determinar e exibir o nome e a nota do aluno com a MAIOR nota.

**•** Determinar e exibir o nome e a nota do aluno com a MENOR nota.

**•** Listar nominalmente todos os alunos Aprovados (Nota ≥ 7.0) e Em Recuperação
(Nota < 7.0).

**3.4** **Módulo de Busca por Aluno**

**•** Permitir ao utilizador introduzir o nome (ou parte do nome) de um aluno para
consulta.

**•** Utilizar a função strcmp (ou strstr) da biblioteca <string.h> para localizar o
estudante no vetor de nomes.

**•** **Se localizado:** Exibir Nome, Nota e Situação (Aprovado ou Em Recuperação).

**•** **Se não localizado:** Exibir mensagem a informar que o aluno não consta no
registo.

**3.5** **Interface e Menu Interativo**
O programa deve ser gerido por um menu principal em laço do-while e estrutura switch-
case com as seguintes opções:

**1** Registar Alunos e Notas

**2** Exibir Relatório Geral (Média, Maior e Menor nota)

**3** Listar Alunos Aprovados / Em Recuperação

**4** Procurar Aluno por Nome

**5** Sair do Programa