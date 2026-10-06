//Atividade Desafio

/* 
Sometimes some words like "localization" or "internationalization" are so long
that writing them many times in one text is quite tiresome.

Let's consider a word too long, if its length is strictly more than 10 characters. All too long
words should be replaced with a special abbreviation

This abbreviation is made like this: we write down the first and the last letter of a word and
between them we write the number of letters between the first and the last letters. That
number is in decimal system and doesn't contain any leading zeroes.

Thus, "localization" will be spelt as "l10n", and "internationalization» will be spelt as "i18n".

You are suggested to automatize the process of changing the words with abbreviations. At that all too long words should be repa-
ced by the abbreviation and the words that are not too long should not undergo any changes.

Input
The first line contains an integer n (1 ≤ n ≤ 100). Each of the following n lines contains one word. All the words consist
of lowercase Latin letters and possess the lengths of from 1 to 100 characters.

Output
Print n lines. The i-th line should contain the result of replacing of the i-th word from the input data.

Input                                                             Output
4                                                                 word
word                                                              l10n
localization                                                      i18n
internationalization                                              p43s
pneumonoultramicroscopicsilicovolcanoconiosis
*/
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char word[101];

    scanf("%d", &n);

    while (n--) {
        scanf("%s", word);
        int len = strlen(word);

        if (len > 10)
            printf("%c%d%c\n", word[0], len - 2, word[len - 1]);
        else
            printf("%s\n", word);
    }

    return 0;
}


/*
Capitalization is writing a word with its first letter as a capital letter. Your task is to capitalize the given word.

Note, that during capitalization all the letters except the first one remains unchanged.

Input
A single line contains a non-empty word. This word consists of lowercase and uppercase English letters. The length of the word 
will not exceed 103.

Output
Output the given word after capitalization.

Input      Output
ApPLe      ApPLe
konjac     Konjac
*/
#include <stdio.h>
#include <ctype.h>

int main() {
    char name[1001];
     
    scanf("%s", name);
    name[0] = toupper(name[0]);

    printf("%s\n", name);

    return 0;
}


/*
You've got a 5 × 5 matrix, consisting of 24 zeroes and a single number one. Let's index the matrix rows by numbers from 1 to 5 
from top to bottom, let's index the matrix columns by numbers from 1 to 5 from left to right. In one move, you are allowed to 
apply one of the two following transformations to the matrix:

Swap two neighboring matrix rows, that is, rows with indexes i and i + 1 for some integer i (1 ≤ i < 5).
Swap two neighboring matrix columns, that is, columns with indexes j and j + 1 for some integer j (1 ≤ j < 5).
You think that a matrix looks beautiful, if the single number one of the matrix is located in its middle (in the cell that is on 
the intersection of the third row and the third column). Count the minimum number of moves needed to make the matrix beautiful.

Input
The input consists of five lines, each line contains five integers: the j-th integer in the i-th line of the input represents the 
element of the matrix that is located on the intersection of the i-th row and the j-th column. It is guaranteed that the matrix 
consists of 24 zeroes and a single number one.

Output
Print a single integer — the minimum number of moves needed to make the matrix beautiful.

Input                    Output
0 0 0 0 0                3
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

Input                    Output
0 0 0 0 0                1
0 0 0 0 1
0 1 0 0 0
0 0 0 0 0
0 0 0 0 0
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, i, nun = 0;

    for (i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            scanf("%d", &x);
            if (x == 1)
                nun = nunDois(i - 3) + nunDois(j - 3);
        }
    }

    printf("%d\n", nun);

    return 0;
}


/*
One day three best friends Petya, Vasya and Tonya decided to form a team and take part in programming contests. Participants are 
usually offered several problems during programming contests. Long before the start the friends decided that they will implement 
a problem if at least two of them are sure about the solution. Otherwise, the friends won't write the problem's solution.

This contest offers n problems to the participants. For each problem we know, which friend is sure about the solution. Help the 
friends find the number of problems for which they will write a solution.

Input
The first input line contains a single integer n (1 ≤ n ≤ 1000) — the number of problems in the contest. Then n lines contain 
three integers each, each integer is either 0 or 1. If the first number in the line equals 1, then Petya is sure about the 
problem's solution, otherwise he isn't sure. The second number shows Vasya's view on the solution, the third number shows Tonya's 
view. The numbers on the lines are separated by spaces.

Output
Print a single integer — the number of problems the friends will implement on the contest.

Examples
Input         Output
3             2
1 1 0
1 1 1
1 0 0

Input         Output
2             1
1 0 0
0 1 1

Note
In the first sample Petya and Vasya are sure that they know how to solve the first problem and all three of them know how to 
solve the second problem. That means that they will write solutions for these problems. Only Petya is sure about the solution for 
the third problem, but that isn't enough, so the friends won't take it.

In the second sample the friends will only implement the second problem, as Vasya and Tonya are sure about the solution.
*/
#include <stdio.h>

int main() {
    int n, a, b, c, count = 0;

    scanf("%d", &n);

    while (n--) {

        scanf("%d %d %d", &a, &b, &c);
        if (a + b + c >= 2)
            count++;
    }

    printf("%d\n", count);

    return 0;
}


/*
There are n stones on the table in a row, each of them can be red, green or blue. Count the minimum number of stones to take from 
the table so that any two neighboring stones had different colors. Stones in a row are considered neighboring if there are no 
other stones between them.

Input
The first line contains integer n (1 ≤ n ≤ 50) — the number of stones on the table.

The next line contains string s, which represents the colors of the stones. We'll consider the stones in the row numbered from 1 
to n from left to right. Then the i-th character s equals "R", if the i-th stone is red, "G", if it's green and "B", if it's blue.

Output
Print a single integer — the answer to the problem.

Examples

Input           Output
3               1
RRG

Input           Output
5               4
RRRRR

Input           Output
4               0
BRBG
*/
#include <stdio.h>

int main() {
    int n, count = 0;
    char s[51];

    scanf("%d", &n);
    scanf("%s", s);

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1])
            count++;
    }

    printf("%d\n", count);

    return 0;
}


/*
Valera the Horse is going to the party with friends. He has been following the fashion trends for a while, and he knows that it 
is very popular to wear all horseshoes of different color. Valera has got four horseshoes left from the last year, but maybe some 
of them have the same color. In this case he needs to go to the store and buy some few more horseshoes, not to lose face in front 
of his stylish comrades.

Fortunately, the store sells horseshoes of all colors under the sun and Valera has enough money to buy any four of them. However, 
in order to save the money, he would like to spend as little money as possible, so you need to help Valera and determine what is 
the minimum number of horseshoes he needs to buy to wear four horseshoes of different colors to a party.

Input
The first line contains four space-separated integers s1, s2, s3, s4 (1 ≤ s1, s2, s3, s4 ≤ 109) — the colors of horseshoes Valera 
has.

Consider all possible colors indexed with integers.

Output
Print a single integer — the minimum number of horseshoes Valera needs to buy.

Examples
Input            Output
1 7 3 3          1

Input            Output
7 7 7 7          3
*/
#include <stdio.h>

int main() {
    int s[4], buy = 0;

    for (int i = 0; i < 4; i++)
        scanf("%d", &s[i]);

    for (int i = 0; i < 4; i++) {
        int repetido = 0;
        for (int j = 0; j < i; j++) {
            if (s[i] == s[j]) {
                repetido = 1;
                break;
            }
        }
        buy += repetido;
    }

    printf("%d\n", buy);

    return 0;
}


/*
Manao works on a sports TV. He's spent much time watching the football games of some country. After a while he began to notice 
different patterns. For example, each team has two sets of uniforms: home uniform and guest uniform. When a team plays a game at 
home, the players put on the home uniform. When a team plays as a guest on somebody else's stadium, the players put on the guest 
uniform. The only exception to that rule is: when the home uniform color of the host team matches the guests' uniform, the host 
team puts on its guest uniform as well. For each team the color of the home and guest uniform is different.

There are n teams taking part in the national championship. The championship consists of n·(n - 1) games: each team invites each 
other team to its stadium. At this point Manao wondered: how many times during the championship is a host team going to put on 
the guest uniform? Note that the order of the games does not affect this number.

You know the colors of the home and guest uniform for each team. For simplicity, the colors are numbered by integers in such a 
way that no two distinct colors have the same number. Help Manao find the answer to his question.

Input
The first line contains an integer n (2 ≤ n ≤ 30). Each of the following n lines contains a pair of distinct space-separated 
integers hi, ai (1 ≤ hi, ai ≤ 100) — the colors of the i-th team's home and guest uniforms, respectively.

Output
In a single line print the number of games where the host team is going to play in the guest uniform.

Examples
Input             Output
3                 1
1 2
2 4
3 4

Input             Output
4                 5
100 42
42 100
5 42
100 5

Input             Output
2                 0
1 2
1 2

Note
In the first test case the championship consists of 6 games. The only game with the event in question is the game between teams 2 
and 1 on the stadium of team 2.

In the second test sample the host team will have to wear guest uniform in the games between teams: 1 and 2, 2 and 1, 2 and 3, 3 
and 4, 4 and 2 (the host team is written first).
*/
#include <stdio.h>

int main() {
    int n, h[30], a[30], count = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d %d", &h[i], &a[i]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && h[i] == a[j])
                count++;
        }
    }

    printf("%d\n", count);

    return 0;
}


/*
Mad scientist Mike entertains himself by arranging rows of dominoes. He doesn't need dominoes, though: he uses rectangular 
magnets instead. Each magnet has two poles, positive (a "plus") and negative (a "minus"). If two magnets are put together at a 
close distance, then the like poles will repel each other and the opposite poles will attract each other.

Mike starts by laying one magnet horizontally on the table. During each following step Mike adds one more magnet horizontally to 
the right end of the row. Depending on how Mike puts the magnet on the table, it is either attracted to the previous one (forming 
a group of multiple magnets linked together) or repelled by it (then Mike lays this magnet at some distance to the right from the 
previous one). We assume that a sole magnet not linked to others forms a group of its own.

Mike arranged multiple magnets in a row. Determine the number of groups that the magnets formed.

Input
The first line of the input contains an integer n (1 ≤ n ≤ 100000) — the number of magnets. Then n lines follow. The i-th line 
(1 ≤ i ≤ n) contains either characters "01", if Mike put the i-th magnet in the "plus-minus" position, or characters "10", if 
Mike put the magnet in the "minus-plus" position.

Output
On the single line of the output print the number of groups of magnets.

Examples

Input            Output
6                3
10
10
10
01
10
10

Input            Output
4                2 
01
01
10
10

Note
The first testcase corresponds to the figure. The testcase has three groups consisting of three, one and two magnets.

The second testcase has two groups, each consisting of two magnets.
*/
#include <stdio.h>

int main() {
    int n, groups = 1;
    char prev[3], cur[3];

    scanf("%d", &n);
    scanf("%s", prev);

    for (int i = 1; i < n; i++) {
        scanf("%s", cur);
        if (cur[0] != prev[0])
            groups++;
        prev[0] = cur[0];
    }

    printf("%d\n", groups);

    return 0;
}