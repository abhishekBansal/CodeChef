/*
http://www.codechef.com/problems/TEST

Your program is to use the brute-force approach in order to find the Answer to Life, the Universe, and Everything. More precisely... 
rewrite small numbers from input to output. Stop processing input after reading in the number 42. All numbers at input are integers of one or two digits

Example

Input:
1
2
88
42
99

Output:
1
2
88

*/

#include <iostream>
#include <stdio.h>

#define TEST 1

// well ! i know its lame but m just doing it cuz title is so tempting :P
int main()
{
#if TEST
    // open file to read it like stdin
    freopen("input.txt", "r", stdin);

    // open file to use as stdout
    freopen("output.txt", "w", stdout);
#endif

    // read values from file
    int no;
    scanf("%d", &no);
    while (no !=42)
    {
        printf("%d\n", no);
        scanf("%d", &no);
    }

    return 0;
}