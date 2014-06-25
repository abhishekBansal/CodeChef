/*
http://www.codechef.com/problems/TAPALIN

Do you know that The Chef has a special interest in palindromes? Yes he does! Almost all of the dishes in his restaurant is named by a palindrome strings. 
The problem is that a name of a dish should not be too long, so The Chef has only limited choices when naming a new dish.
For the given positive integer N, your task is to calculate the number of palindrome strings of length not exceeding N, that contain only lowercase letters 
of English alphabet (letters from 'a' to 'z', inclusive). Recall that a palindrome is a string that reads the same left to right as right to left (as in "radar").

For example:
For N = 1, we have 26 different palindromes of length not exceeding N:
"a", "b", ..., "z".
For N = 2 we have 52 different palindromes of length not exceeding N:
"a", "b", ..., "z",
"aa", "bb", ..., "zz".
For N = 3 we have 728 different palindromes of length not exceeding N:
"a", "b", ..., "z",
"aa", "bb", ..., "zz",
"aaa", "aba", ..., "aza",
"bab", "bbb", ..., "bzb",
...,
"zaz", "zbz", ..., "zzz".

Since the answer can be quite large you should output it modulo 1000000007 (109 + 7). Yes, we know, most of you already hate this modulo, but there is nothing we can do with it :)

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows. The only line of each test case contains a single integer N.

Output
For each test case, output a single line containing the answer for the corresponding test case.

Constrains

 
1 ≤ T ≤ 1000
1 ≤ N ≤ 109
 
Example

Input:
5
1
2
3
4
100

Output:
26
52
728
1404
508533804
*/

#include <iostream>
#include <math.h>
#include <stdio.h>

// so it should be easy, but lets see (fingerscrossed)

#define MOD_NO 1000000007

#define TEST 1

unsigned long long int bigPowerMod(unsigned long long base, unsigned long exponent, unsigned long mod)
{
    unsigned long long temp = base;
    for(unsigned long i = 1; i < exponent; i++)
    {
        base = temp * base % mod;
    }
     return base % mod;
}

/*
*Exponentian by squaring
*Best Explanantion here http://www.programminglogic.com/fast-exponentiation-algorithms/
*/
unsigned long long power(unsigned long long base, unsigned long long exponent, unsigned long long modulus)
{
    unsigned long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent >>= 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main()
{
#if TEST
    // open file to read it like stdin
    freopen("input.txt", "r", stdin);

    // open file to use as stdout
    freopen("output.txt", "w", stdout);
#endif

    unsigned int noOfTestCases;
    scanf("%d", &noOfTestCases);

    for(int i=0; i < noOfTestCases; i++)
    {
        int N;
        scanf("%d", &N);

        unsigned long long result = 0;

/**
* Following solution works but exceeds time limit. Lets try something else
*
        for(int j=1; j <= N; ++j)
        {
            if(j%2)
            {
                result = (result%MOD_NO) + bigPowerMod(26, (j+1)/2, MOD_NO) ;
            }
            else
            {
                result = (result%MOD_NO) + bigPowerMod(26, j/2, MOD_NO) ;
            }
        }
*
*
*/
        /**
        * http://math.stackexchange.com/questions/681200/palindromes-of-length-less-than-or-equal-to-n
        * try to use sum of geometric progression method
        * here this magic no(280000002) is inverse modulo instead of dividing by 25
        * tried banging my head on fermet theorem but couldn't understand it
        * used following links instead
        * http://discuss.codechef.com/questions/7695/tapalin-editorial
        * http://www.cs.princeton.edu/~dsri/modular-inversion.html
        * got TLE again O_O ;(
        * Removed my pthatic power calculation function and used somebody else's(http://www.codechef.com/viewsolution/1964279) function which uses 
        * Exponentian by squaring(http://en.wikipedia.org/wiki/Exponentiation_by_squaring) method :-/ :-(
        */
        if(N&1) // if N is odd
        {
            if(N != 1)
            {
                unsigned long long temp = power(26, (N - 1)/2, MOD_NO);
                unsigned long long extra = power(26, (N + 1)/2, MOD_NO);
                result =  ( ( (26) * (temp - 1) * 280000002 ) % MOD_NO) * 2 + extra;
            }
            else
            {
                result = 26;
            }
        }
        else // if N is even
        {
             unsigned long long temp = power(26, N/2, MOD_NO);
             result =  ( (26 * ((temp - 1) * 280000002) ) % MOD_NO) * 2;
        }

        printf("%ld\n", result % MOD_NO);
    }
}