/*
http://www.codechef.com/problems/CANDLE

The chef is preparing a birthday cake for one of his guests,
and his decided to write the age of the guest in candles on the cake.
There are 10 types of candles, one for each of the digits '0' through '9'.
The chef has forgotten the age of the guest, however, so doesn't know whether he has enough candles of the right types.
For example, if the guest were 101 years old, the chef would need two '1' candles and one '0' candle.
Given the candles the chef has, your task is to determine the smallest positive integer that cannot be represented with those candles.

Input:
Input will begin with an integer T≤100, the number of test cases.
Each test case consists of a single line with exactly 10 integers, each between 0 and 8, inclusive.
The first integer of each test case represents the number of '0' candles the chef has,
the second integer represents the number of '1' candles the chef has, and so on.

Output:
For each test case, output on a single line the smallest positive integer that cannot be expressed with the given candles.

Sample input:

3
2 1 1 4 0 6 3 2 2 2
0 1 1 1 1 1 1 1 1 1
2 2 1 2 1 1 3 1 1 1
 
Sample output:

4
10
22

*/


/*
This problem took lot of time :'(
Here are some tricky test cases

Input
2 3 4 4 4 3 4 5 6 7
0 2 2 2 4 1 3 6 7 3
0 2 2 2 4 6 3 6 7 3
0 2 2 1 4 6 3 6 7 3
0 0 1 2 3 4 5 6 7 8
2 1 1 4 0 6 3 2 2 2
0 1 1 1 1 1 1 1 1 1
2 2 1 2 1 1 3 1 1 1
6 3 3 4 3 3 2 3 3 3
6 3 3 4 3 2 2 3 3 3
2 3 3 4 3 2 2 3 3 3

Output
1000
10
10
10
1
4
10
22
666
555
555
*/

#include <iostream>
#include <stdio.h>

#define TEST 1

int candleCount[10];

int main()
{
#if TEST
    // open file to read it like stdin
    freopen("input.txt", "r", stdin);

    // open file to use as stdout
    freopen("output.txt", "w", stdout);
#endif

    // start reading file
    int n;
    scanf("%d", &n);

    // test cases end with n = 0
    while (n > 0)
    {
        //populate array
        // and we will see what is min count
        for(int i=0; i < 10; i++)
        {
            scanf("%d", &candleCount[i]);
        }

        // now we keep on finding min counts and pushThoseCandle nos in a integer no
        int number[100];
        int k=0;
        while(1)
        {
            int min = candleCount[0];
            int minCandleNo = -1;
            for(int i=0; i < 10; i++)
            {
                if(candleCount[i] < min)
                {
                    min = candleCount[i];
                }
            }

            // find first candle with this count
            for(int i=1; i < 10; i++)
            {
                if(candleCount[i] == min)
                {
                    minCandleNo = i;
                    break;
                }
            }

            // if we have minimum candles of no 0 then handle it differently
            if(minCandleNo == -1)  // -1 value indicates that candle with no 0 was having min count and it was the only candle with that count
            {
                // check if there is any other zero, if there is then thats our answer otherwise
                // answer is 1*0
                int zeroNo = min;
                min = candleCount[1];
                bool zeroFound = false;
                for(int i=1; i < 10; i++)
                {
                    if(candleCount[i] == 0)
                    {
                        printf("%d\n", i);
                        zeroFound = true;
                        break;
                    }
                }

                if(!zeroFound)
                {
                    printf("1");
                    for(int i = 0; i <= zeroNo; i++)
                        printf("0");

                    printf("\n");
                }

                break;
            }
            else
            {
                // we have already used one of this candle
                candleCount[minCandleNo]--;

                number[k] = minCandleNo;
                k++;

                if(candleCount[minCandleNo] < 0)
                {
                    for(int i=0; i < k; i++)
                    {
                        printf("%d", number[i]);
                    }
                    printf("\n");
                    break;
                }
            }
        }

        n--;
    }

    return 0;
}