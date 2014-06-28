/*
http://www.codechef.com/problems/INTEST


The purpose of this problem is to verify whether the method you are using to read input data is sufficiently fast to handle problems branded with the enormous 
Input/Output warning. You are expected to be able to process at least 2.5MB of input data per second at runtime.
Input

The input begins with two positive integers n k (n, k<=107). The next n lines of input contain one positive integer ti, not greater than 109, each.
Output

Write a single integer to output, denoting how many integers ti are divisible by k.
Example

Input:
7 3
1
51
966369
7
9
999996
11

Output:
4

*/

#include <iostream>
#include <stdio.h>

#define TEST 1

int main()
{
#if TEST
    // open file to read it like stdin
    freopen("input.txt", "r", stdin);

    // open file to use as stdout
    freopen("output.txt", "w", stdout);
#endif

    // read values from file
    unsigned long long int n, k, count = 0;

    scanf("%lld %lld", &n, &k);
    unsigned long long temp;

    while (0 < n)
    {
        scanf("%lld", &temp);

        if(!(temp % k))
            count++;
        --n;
    }

    printf("%lld", count);
    return 0;
}