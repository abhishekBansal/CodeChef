/*
http://www.codechef.com/problems/NOLOGIC

Consider the following dialog.
- Father, what is the lack of logic?
- Bunny.
- Where?
- Day.

As you see, father's answers have no logic demonstrating the son the notion of "lack of logic" using live example :D
Let's try to formalize things. Note that both father's answers have no common letters with the corresponding questions.
Probably this is the reason. Let's say that the answer has no logic if it has no common letters with the question. 
Your task is to write a bot that will answer annoying comments of contestants at codechef using this definition. 
Note that letter denotes a lowercase or uppercase English alphabet (ASCII code from 65 to 90 or from 97 to 122).
Namely, you will be given several questions and you need to produce answers to these questions that have no logic. 
Note that lowercase and uppercase letters are considered the same when treating "no common letters" rule. Also note
that this rule concerns only letters. The answer should contain at least one letter. If it is impossible to produce 
such answer then output "~" (tilde sign, quotes are for clarity).

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases
follows. The only line of each test case contains the question. The question is a non-empty string where each character
has ASCII code from 32 to 126, inclusive (refer to this).

Output
For each test case, output a single line containing the answer to this question that has no logic or "~" (quotes for 
clarity) if it is impossible to find such answer. Each character in the answer should be either a space (ASCII code 32), 
or the letter of English alphabet (lowercase or uppercase). Recall that the answer should contain at least one letter. 
The number of characters in the answer should not exceed 314. You can output any answer satisfying these constraints 
that has no logic.

Note! Special judge is very strict for this problem and check your output character-by-character. Be sure that you follow 
the mentioned output format precisely. For instance, your output should contain exactly T new-line characters (ASCII code 10)
- one after each answer.

Constraints
1 ≤ T ≤ 314
1 ≤ the number of characters in the question ≤ 314
Example

Input:
4
Father, what is the lack of logic?
Where?
The quick brown fox jumps over the lazy dog.
!!!

Output:
Bunny
Day
~
You Can output aLoMsT anytihng HERE

Explanation
Example cases 1 and 2 correspond to the dialog in the problem statement. Note that we don't print dots since it is allowed
to have only spaces and letters in the answer.
In example case 3 each letter of English alphabet is used in the question. Hence we can't produce the answer that has no logic.

*/

#include <iostream>
#include <stdio.h>
#include <string>

#define TEST 1

char alphabets[26];
char ques[315];

int main()
{
#if TEST
    // open file to read it like stdin
    freopen("input.txt", "r", stdin);

    // open file to use as stdout
    freopen("output.txt", "w", stdout);
#endif

    // read values from file
    unsigned int nTC, count = 0;

    scanf("%d", &nTC);
    // ignore a line end
    getchar();
    while (0 < nTC)
    {
        int noOfBytes = 314;
        std::string curQues;
        std::getline(std::cin, curQues);
        int len = curQues.length();

        // reset alphabets array
        for(int i = 0; i < 26; i++)
        {
            alphabets[i] = 0;
        }

        // track what all alphabets came i guess we can ignore all other 
        // characters (fingerscrossed)
        for(int i = 0; i < curQues.length(); i++)
        {
            if(curQues[i] >= 65 && curQues[i] <= 90)
            {
                alphabets[curQues[i] - 65] = 1;
            }
            else if(curQues[i] >= 97 && curQues[i] <= 122)
            {
                alphabets[curQues[i] - 97] = 1;
            }
        }

        // now print whatever not came
        // a boolean to keep tilde track
        bool isTilde = true;
        for(int i = 0; i < 26; i++)
        {
            if(!alphabets[i])
            {
                putchar(i + 65);
                isTilde = false;
            }
        }

        if(isTilde)
            putchar('~');

        printf("\n");

        --nTC;
    }
    return 0;
}