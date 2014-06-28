/*
http://www.codechef.com/problems/HOLES


Chef wrote some text on a piece of paper and now he wants to know how many holes are in the text. What is a hole? 
If you think of the paper as the plane and a letter as a curve on the plane, then each letter divides the plane into regions. 
For example letters "A", "D", "O", "P", "R" divide the plane into two regions so we say these letters each have one hole. Similarly, 
letter "B" has two holes and letters such as "C", "E", "F", "K" have no holes. We say that the number of holes in the text is equal
to the total number of holes in the letters of the text. Help Chef to determine how many holes are in the text.

Input
The first line contains a single integer T <= 40, the number of test cases. T test cases follow. The only line of each test case 
contains a non-empty text composed only of uppercase letters of English alphabet. 
The length of the text is less then 100. There are no any spaces in the input.

Output
For each test case, output a single line containing the number of holes in the corresponding text.

Example

Input:
2
CODECHEF
DRINKEATCODE

Output:
2
5

*/

#include <iostream>
#include <stdio.h>

#define TEST 1

// i did it like this but i suppose reading full string and then processing will be much faster 
int main()
{
#if TEST
    // open file to read it like stdin
    freopen("input.txt", "r", stdin);

    // open file to use as stdout
    freopen("output.txt", "w", stdout);
#endif

    // read values from file
    unsigned int n, count = 0;

    scanf("%d", &n);

    // ignore first new line
    getchar();
    while (0 < n)
    {
        char ch = getchar();

        if(ch == 'A' || ch == 'D' || ch == 'O' ||ch == 'P' ||ch == 'Q' || ch == 'R' )
            count ++;
        else if(ch == 'B')
            count += 2;
        else if(ch == '\n' || ch < 0) // new line or end of file
        {
            printf("%d\n", count);
            count = 0;
            --n;
        }
    }
    return 0;
}