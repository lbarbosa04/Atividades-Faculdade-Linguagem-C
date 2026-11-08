# Projeto Final – Cadastro de Alunos e Boletim Escolar em C

**Curso:** Análise e Desenvolvimento de Sistemas / Engenharia de Software
**Projeto 3:** Vetores, Funções e Struct
**Apresentação:** Seminário de Avaliação do Projeto Final, em 12/11/2026

## Grupo (3 a 4 alunos)

- _(preencher com os nomes dos integrantes)_

## O projeto

Cada grupo desenvolve um **programa em C, em console, para cadastro de alunos e geração de boletim escolar**. O programa usa um **vetor de struct** para guardar os alunos e **funções** para cada operação do menu, reunindo tudo o que foi visto no Projeto 3.

## O que o programa deve fazer

- Cadastrar alunos com matrícula, nome e turma.
- Lançar e alterar as notas de cada aluno em 4 disciplinas fixas (ex.: Português, Matemática, Ciências e História) e 4 bimestres.
- Listar todos os alunos, buscar por matrícula e remover um cadastro.
- Emitir o **boletim** de um aluno: notas por bimestre, média por disciplina, média geral e situação.
- Gerar o **relatório da turma**: média geral da turma, aluno com maior média e quantidade de aprovados, em recuperação e reprovados.

### Situação por disciplina

| Situação    | Média         |
| ----------- | ------------- |
| Aprovado    | 6,0 ou mais   |
| Recuperação | de 4,0 a 5,9  |
| Reprovado   | abaixo de 4,0 |

### Exemplo de boletim no console

```
========== BOLETIM ESCOLAR ==========
Aluno: Ana Souza   Matricula: 101   Turma: 2A
-------------------------------------
Disciplina   B1   B2   B3   B4  Media  Situacao
Portugues   7.0  8.0  6.5  7.5   7.25  Aprovado
Matematica  5.0  4.5  6.0  5.5   5.25  Recuperacao
Ciencias    8.0  9.0  8.5  9.0   8.62  Aprovado
Historia    6.0  7.0  6.0  6.5   6.38  Aprovado
-------------------------------------
Media geral: 6.88
=====================================
```

## Requisitos mínimos

- Uma struct `Aluno` com matrícula, nome, turma e as notas guardadas em vetor ou matriz (disciplina × bimestre).
- Um vetor de `Aluno` com capacidade para pelo menos 50 alunos e um contador de quantos estão cadastrados.
- Constantes com `#define` para os limites e as regras (capacidade, número de disciplinas e de bimestres, médias de corte).
- Menu em laço (`do-while` + `switch`) com as opções: cadastrar, listar, buscar, lançar/alterar notas, remover, emitir boletim, relatório da turma e sair.
- Cada opção do menu em uma **função própria**, recebendo o vetor e o contador por parâmetro (sem variáveis globais, exceto constantes como os nomes das disciplinas).
- Funções de cálculo separadas da exibição, por exemplo `calcularMediaDisciplina` e `situacao`, que devolvem o valor com `return`.
- Validações: matrícula repetida, notas fora de 0 a 10, vetor cheio e matrícula não encontrada.

## Entregas

- [ ] Arquivo `.c` do sistema, compilando sem erros, enviado antes da apresentação.

## Critérios de avaliação

| Critério                          | O que se observa                                                                                     | Peso |
| --------------------------------- | ---------------------------------------------------------------------------------------------------- | ---- |
| Funcionamento                     | Todas as opções do menu funcionam sem travar                                                         | 30%  |
| Uso de struct e vetor             | Struct do aluno bem modelada, com as notas em vetor/matriz, e vetor de struct usado corretamente     | 20%  |
| Funções                           | Lógica dividida em funções com parâmetros e retorno adequados                                        | 20%  |
| Boletim, relatório e validações   | Médias e situações corretas, boletim legível e tratamento dos casos de erro                          | 15%  |
| Apresentação                      | Clareza, participação de todos e domínio do código ao responder perguntas                            | 15%  |
