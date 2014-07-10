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

// okay ! so last time i implemented it TLE was slapped on my face.. will try following solution now
// http://www.geeksforgeeks.org/find-number-of-triangles-possible/

// using CCP technology directly :P


/* Following function is needed for library function qsort(). Refer
   http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
int comp(const void* a, const void* b)
{  
    return *(int*)a > *(int*)b ; 
}

// Function to count all possible triangles with arr[] elements
int findNumberOfTriangles(unsigned long arr[], int n)
{
    // Sort the array elements in non-decreasing order
    qsort(arr, n, sizeof( arr[0] ), comp);
 
    // Initialize count of triangles
    int count = 0;
 
    // Fix the first element.  We need to run till n-3 as the other two elements are
    // selected from arr[i+1...n-1]
    for (int i = 0; i < n-2; ++i)
    {
        // Initialize index of the rightmost third element
        int k = i+2;
 
        // Fix the second element
        for (int j = i+1; j < n; ++j)
        {
            // Find the rightmost element which is smaller than the sum
            // of two fixed elements
            // The important thing to note here is, we use the previous
            // value of k. If value of arr[i] + arr[j-1] was greater than arr[k],
            // then arr[i] + arr[j] must be greater than k, because the
            // array is sorted.
            while (k < n && arr[i] + arr[j] >= arr[k])
               ++k;
 
            // Total number of possible triangles that can be formed
            // with the two fixed elements is k - j - 1.  The two fixed
            // elements are arr[i] and arr[j].  All elements between arr[j+1]
            // to arr[k-1] can form a triangle with arr[i] and arr[j].
            // One is subtracted from k because k is incremented one extra
            // in above while loop.
            // k will always be greater than j. If j becomes equal to k, then
            // above loop will increment k, because arr[k] + arr[i] is always
            // greater than arr[k]
            // count += k - j - 1;

            // BUT
            // for this problem we are interested in how many triplets cannot form triangle
            count = count + n - k;
        }
    }
 
    return count;
}

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

        unsigned long int tri = findNumberOfTriangles(sticks, n);
        printf("%d\n", tri);

        scanf("%d", &n);
    }
    return 0;
}