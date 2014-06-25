#include <iostream>
#define MOD_NO 1000000007

void rightShift(int no)
{
    while( no >= 1 )
    {
        no = no>>1; 
        std::cout<< no << std::endl;
    }
}

unsigned long long int bigPowerMod(unsigned long long base, unsigned long exponent, unsigned long mod)
{
    unsigned long long temp = base;
    for(unsigned long i = 1; i < exponent; i++)
    {
        base = temp * base % mod;
    }
     return base % mod;
}

int main()
{
    std::cout<<std::endl<<bigPowerMod(2, 10, MOD_NO);
    std::cout<<std::endl<<bigPowerMod(3, 10, MOD_NO);
    std::cout<<std::endl<<bigPowerMod(8, 10, MOD_NO);
    std::cout<<std::endl<<bigPowerMod(10, 10, MOD_NO);
    return 0;
}