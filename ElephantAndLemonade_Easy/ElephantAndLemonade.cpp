/* 
http://www.codechef.com/problems/LELEMON

Little Elephant likes lemonade.
When Little Elephant visits any room, he finds the bottle of the lemonade in that room that contains the 
greatest number of litres of lemonade and drinks it all.
There are n rooms (numbered from 0 to n-1), each contains Ci bottles. Each bottle has a volume (in litres). 
The first room visited by Little Elephant was P0-th, the second - P1-th, ..., the m-th - Pm-1-th room.
Note that Little Elephant may visit a room more than once.

Find for Little Elephant the total volume of lemonade he has drunk.

Input
First line of the input contains single integer T - the number of test cases. T test cases follow. 
First line of each test case contains pair of integers n and m. Second line contains m integers separated by 
a single space - array P. Next n lines describe bottles in each room in such format: Ci V0 V1 ... VCi-1, 
where V is the list of volumes (in liters) of all bottles in i-th room.

Output
In T lines print T integers - the answers for the corresponding test cases.

Constraints
1 <= T <= 10
1 <= n, Ci <= 100
1 <= m <= 10^4
0 <= Pi < n
1 <= Vi <= 10^5

Example

Input:
2
3 3
0 2 1
3 1 2 3
1 7
2 4 7
4 7
0 1 3 0 1 0 0
1 7
3 9 4 5
7 1 2 3 4 5 6 7
1 1

Output:
17
22
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
    int noOfCases;
    scanf("%d", &noOfCases);

    while (noOfCases > 0)
    {
        int noOfRooms, m;
        scanf("%d", &noOfRooms);
        scanf("%d", &m);

        // the P array
        int* visitOrder = new int[m];
        for(int i = 0; i < m; i++)
        {
            scanf("%d", &visitOrder[i]);
        }

        // lets create 2D matrix for bottles and rooms
        // at mat[i][0] we will store no of bottles in ith room and then volume in respective bottles in rest of array
        int **bottleVolMat = new int*[noOfRooms];

        for(int i = 0; i < noOfRooms; i++)
        {
            // read ci
            int noOfBottles = 0;
            scanf("%d", &noOfBottles);

            bottleVolMat[i] = new int[noOfBottles + 1];
            bottleVolMat[i][0] = noOfBottles;
            for(int j = 1; j <= noOfBottles; j++)
            {
                scanf("%d", &bottleVolMat[i][j]);
            }
        }

        // now lets start visiting and collecting lemonade 
        // for our Little Elephant
        unsigned long result = 0;
        for(int i = 0; i < m; i++)
        {
            int room = visitOrder[i];
            int noOfBottles = bottleVolMat[room][0];
            // drink max vol bottle in this room 
            // we have bottles in bottleVolMat
            unsigned int maxVol = 0, index = 1;
            for(int j = 1; j <= noOfBottles; j++)
            {
                if(bottleVolMat[room][j] > maxVol)
                {
                    maxVol = bottleVolMat[room][j];
                    index = j;
                }
            }
            result += maxVol;
            // mark volume as zero as its already in stomach :D
            bottleVolMat[room][index] = 0;
        }

        printf("%d\n", result);

        --noOfCases;
        delete [] visitOrder;

        for(int i = 0; i < noOfRooms; i++)
        {
            delete [] bottleVolMat[i];
        }
        delete [] bottleVolMat;
    }
}