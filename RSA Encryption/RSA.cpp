
#include "../std_lib_facilities.h"

bool isPrime(unsigned long long n)
{

    if(n <= 1)
    {
        return false;
    }
    else
    {
        for( unsigned long long i = 2; i < n; i++)
        {
            if(n % i == 0)
            {
                return false;
            }

        }

    }

    return true;




}
unsigned long long getPrime(unsigned long long min, unsigned long long max)
{

    unsigned long long prime_num;
    prime_num = rand() % ((max - min)+ 1) + min;

    if(isPrime(prime_num))
    {

        return prime_num;
    }
    else
    {
           prime_num = getPrime(min, max);
    }

    return prime_num;


}
unsigned long long gcd(unsigned long long x, unsigned long long y)
{

    unsigned long long max;
    unsigned long long max_gcd = 1;
    unsigned long long gcd = 1;
    if(x > y)
    {
        max = x;
    }
    else
    {
        max = y;

    }
    for(unsigned long long i = 1; i <= max; i++)
    {
        if((x % i == 0) && (y % i == 0))
        {

          gcd = i;  
          if(gcd > max_gcd)
          {
              max_gcd = gcd;
          }        

        }

    }

    return max_gcd;




}
unsigned long long lcm(unsigned long long x, unsigned long long y)
{

    unsigned long long min_lcm;
    min_lcm = (x * y) / gcd(x, y);
    return min_lcm;

}
unsigned long long modInverse(unsigned long long e, unsigned long long lam)
{

    unsigned long long d;
    for(unsigned long long i = 1; i <= lam; i++)
    {
        if((i * e) % lam == 1)
        {
            d = i;
            break;

        }

    }

    return d;


}
unsigned long long modExp(unsigned long long base,unsigned long long exp,unsigned long long n)
{
    unsigned long long ans = 1;
    for(unsigned long long i = 0; i < exp; i++)
        ans = (ans * base) % n;
    return ans;

}
