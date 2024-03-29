#include <iostream>
#include <cstdio>

using namespace std;

int pow(int a, int b)
{
    int ans = 1;
    while(b)
    {
        if(b&1)
        {
            ans *= a;
        }
        a *= a;

        b >>= 1;
    }

    return ans;
}

// (a*b)%c=(a%c)*(b%c)%c
int powMod(int a, int b, int c)
{
    int ans = 1;
    a %= c;
    if(!a)
        return 0;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % c;
        a =  (a * a) % c;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int b,p,k;
    cin >> b >> p >> k;
    printf("%d^%d mod %d=%d",b,p,k,powMod(b,p,k));
}