/*
http://www.codechef.com/problems/NOTATRI


You have N (3 ≤ N ≤ 2,000) wooden sticks, which are labeled from 1 to N. The i-th stick has a length of Li (1 ≤ Li ≤ 1,000,000). 
Your friend has challenged you to a simple game: you will pick three sticks at random, and if your friend can form a triangle 
with them (degenerate triangles included), he wins; otherwise, you win. You are not sure if your friend is trying to trick you, 
so you would like to determine your chances of winning by computing the number of ways you could choose three sticks 
(regardless of order) such that it is impossible to form a triangle with them.

Input
The input file consists of multiple test cases. Each test case starts with the single integer N, followed by a line with the 
integers L1, ..., LN. The input is terminated with N = 0, which should not be processed.

Output
For each test case, output a single line containing the number of triples.

Example

Input:
3
4 2 10
3
1 2 3
4
5 2 9 6
6
1 2 4 4 4 4
0

Output:
1
0
2
4

For the first test case, 4 + 2 < 10, so you will win with the one available triple. For the second case, 1 + 2 is equal to 3; 
since degenerate triangles are allowed, the answer is 0.

*/

#include <iostream>
#include <stdio.h>
#include <cstdlib>

#define TEST 1

unsigned long sticks[2000];

// so i guess we will have to calculate all nC3 combinations and check them one by one if they can form a triangle
// this checking can be done using a simple function 
// let try to print all combinations first
// taking help from here http://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/

// CAUTION: 
// gives TLE ;( ;(
// found one efficient solution here will try that in seperate project
// http://www.geeksforgeeks.org/find-number-of-triangles-possible/
static int count = 0;

bool isValidTriangle(unsigned long arr[])
{
    if( ( (arr[0] + arr[1]) >= arr[2] ) && ( (arr[1] + arr[2]) >= arr[0] ) && ( (arr[0] + arr[2]) >= arr[1] ) ) 
        return true;
    else 
        return false;
}

void checkCombinations(unsigned long arr[], unsigned long resArr[], int start, int end, int r, int index)
{
    // termination condition
    if(index == r)
    {
        if(!isValidTriangle(resArr))
            count ++;
        return;
    }

    for(int i=start; i < end; i++)
    {
        resArr[index] = arr[i];
        checkCombinations(arr, resArr, i + 1,  end, 3, index + 1);
        
        // removing duplicates
        //while(arr[i] == arr[i+1])
        //     i++; 
    }
}

void  getCount(unsigned long arr[], int n)
{
    unsigned long data[3];
    count = 0;

    checkCombinations(arr, data, 0, n, 3, 0);
}

/* Following function is needed for library function qsort(). Refer
   http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
//int comp(const void* a, const void* b)
//{  
//    return *(int*)a > *(int*)b ; 
//}

int main()
{
#if TEST
    // open file to read it like stdin
    freopen("input.txt", "r", stdin);

    // open file to use as stdout
    freopen("output.txt", "w", stdout);
#endif

    // read values from file
    unsigned int n;
    scanf("%d", &n);

    // ignore first new line
    getchar();
    while (0 < n)
    {
        for(int i = 0; i < n; i++ )
        {
            scanf("%ld", &sticks[i]);
        }

        count = 0;
        //qsort(sticks, n, sizeof(sticks[0]), comp);
        getCount(sticks, n);

        printf("%d\n", count);

        scanf("%d", &n);
    }
    return 0;
}