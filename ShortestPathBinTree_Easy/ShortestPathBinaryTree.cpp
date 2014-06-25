/* 
http://www.codechef.com/problems/BINTREE

Consider an infinite full binary tree (each node has two children except the leaf nodes) defined as follows. 
For a node labelled v its left child will be labelled 2*v and its right child will be labelled 2*v+1. 
The root is labelled as 1. 

You are given N queries of the form i j. For each query, you have to print the length of the shortest path between node labelled i and node labelled j.
Input

First line contains N, the number of queries. Each query consists of two space separated integers i and j in one line.
Output

For each query, print the required answer in one line.
Constraints

1 ≤ N ≤ 10^5
1 ≤ i,j ≤ 10^9
Example

Input:
3
1 2
2 3
4 3

Output:
1
2
3
Explanation

For first query, 1 is directly connected to 2 by an edge. Hence distance 1.
*/

//#include <iostream>
//#include <set>
//
//int main()
//{
//    // open file to read it like stdin
//    freopen("input.txt", "r", stdin);
//
//    // open file to use as std out
//    freopen("output.txt", "w", stdout);
//
//    // read no of test cases
//    long long noOfTest;
//    std::cin >> noOfTest;
//
//    int k = 0;
//    while(k < noOfTest)
//    {
//        long long i = 0, j = 0;
//        std::cin >> i >> j;
//
//        if(i == j)
//        {
//            k++;
//            std::cout << "0" << std::endl;
//            continue;
//        }
//        k++;
//
//        // for shortest path we try to find common parent to both
//        long long iParent = 0, jParent = 0;
//        long long noIParent = 0, noJParent = 0;
//
//        // we start finding with bigger index
//        // find all parents and store in a set
//        std::set<long long> iParentSet;
//        std::set<long long> jParentSet;
//        if(i > j)
//        {
//            iParent = i;
//            while(1 != iParent)
//            {
//                if(iParent % 2 ==  0)
//                    iParent = iParent/2;
//                else
//                    iParent = (iParent - 1)/2;
//
//                iParentSet.insert(iParent);
//            }
//        }
//        else
//        {
//            jParent = j;
//            while(1 != jParent)
//            {
//                if(jParent % 2 ==  0)
//                    jParent = jParent/2;
//                else
//                    jParent = (jParent - 1)/2;
//
//                jParentSet.insert(jParent);
//            }
//        }
//
//        long long count = 0, result = 0;
//
//        // check special case when one element is parent of other
//        if(iParent > 0)
//        {
//            std::set<long long>::iterator iter = iParentSet.find(j);
//            if(iter != iParentSet.end())
//            {
//                std::set<long long>::iterator beginIter = iParentSet.begin();
//                // count no of parents till common parent
//                while(beginIter != iter)
//                {
//                    beginIter++;
//                    count++;
//                }
//                
//                result = iParentSet.size() - count;
//                std::cout << result << std::endl;
//                continue;
//            }
//        }
//        else
//        {
//            std::set<long long>::iterator iter = jParentSet.find(i);
//            if(iter != jParentSet.end())
//            {
//                std::set<long long>::iterator beginIter = jParentSet.begin();
//                // count no of parents till common parent
//                while(beginIter != iter)
//                {
//                    beginIter++;
//                    count++;
//                }
//                
//                result = jParentSet.size() - count;
//                std::cout << result << std::endl;
//                continue;
//            }
//        }
//
//        // now find parents of second no and see if it already exists in set
//        
//        if(iParent > 0)
//        {
//            jParent = j;
//            
//            if(jParent == 1)
//            {
//                count = 0;
//                result = count + iParentSet.size();
//                std::cout << result << std::endl;
//                continue;
//            }
//            
//            while(jParent != 1)
//            {
//                if(jParent % 2 ==  0)
//                    jParent = jParent/2;
//                else
//                    jParent = (jParent - 1)/2;
//
//                if(jParent != 0)
//                    ++noIParent;
//
//                std::set<long long>::iterator iter = iParentSet.find(jParent);
//                if(iter != iParentSet.end())
//                {
//                   // common parent found
//                    std::set<long long>::iterator beginIter = iParentSet.begin();
//
//                    // count no of parents till common parent
//                    while(beginIter != iter)
//                    {
//                        beginIter++;
//                        count++;
//                    }
//
//                    count = iParentSet.size() - count;
//                    break;
//                }
//            }
//            result = count + noIParent;
//        }
//        else
//        {
//            iParent = i;
//            
//            if(iParent == 1)
//            {
//                count = 0;
//                result = count + jParentSet.size();
//                std::cout << result << std::endl;
//                continue;
//            }
//
//            while(iParent != 1)
//            {
//                if(iParent % 2 ==  0)
//                    iParent = iParent/2;
//                else
//                    iParent = (iParent - 1)/2;
//                
//                if(iParent != 0)
//                    ++noIParent;
//
//                std::set<long long>::iterator iter = jParentSet.find(iParent);
//                if(iter != jParentSet.end())
//                {
//                    // common parent found
//                    std::set<long long>::iterator beginIter = jParentSet.begin();
//
//                    // count no of parents till common parent
//                    while(beginIter != iter)
//                    {
//                        beginIter++;
//                        count++;
//                    }
//
//                    count = jParentSet.size() - count;
//                    break;
//                }
//            }
//            result = count + noIParent;
//        }
//
//        std::cout << result << std::endl;
//    }
//
//    return 0;
//}


/*
So above first crude approach didn't workout. Its working for all test cases i could think of. But not sure what test
cases are failing in CodeChef. Moreover its pthatic code :(.

Edit: Its working now. I was printing 0 twice in case of no are equal (facepalm) (headbang) and stil thats pthatic solution 
       Its taking 17 seconds as compared to 10 seconds of solution below. That took me 4 hrs to code as compared to 15 minutes 
       of solution below :-/

Edit 2: One more bomb. Using C IO (scanf, printf) is much much much faster then C++ streams (cin, cout). Now below solution runs in 1.25 seconds 
        on CodeChef

I saw one logic from internet. lets try that. It seems to be correct at first.

Idea is to divide given no by 2 untill they become equal;
*/

#include <iostream>
#include <stdio.h>
int main()
{
    // open file to read it like stdin
    freopen("input.txt", "r", stdin);

    // open file to use as std out
    freopen("output.txt", "w", stdout);

    // read no of test cases
    long long noOfTest;
    std::cin >> noOfTest;

    int k = 0;
    while(k < noOfTest)
    {
        long long i = 0, j = 0;
        //std::cin >> i >> j;
        scanf("%ld %ld", &i, &j);

        k++;

        // for shortest path we try to find common parent to both
        // start by dividing larger no
        
        long noOfDivisions = 0;
        while(!(i == j))
        {
            if(i > 1 && i > j)
            {
                // right shift is equivalent to devision by 2
                i = i >> 1;
                ++noOfDivisions;
            }
            else if(j > 1)
            {
                j = j >> 1;
                ++noOfDivisions;
            }
        }

        //std::cout << noOfDivisions << std::endl;
        printf("%ld\n", noOfDivisions);
    }
}