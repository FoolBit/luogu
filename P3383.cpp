#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 10000002

int notPrime[MAXN];
int prime[MAXN];
int nprime;

int N,M;

void sieve()
{
    notPrime[0] = notPrime[1] = 1;
    prime[nprime++] = 2;

    for(int i=2; i<=N/2; ++i)
    {
        if(!notPrime[i])
            prime[nprime++] = i;
        for(int j=0; j<nprime; ++j)
        {
            if(i*prime[j]>N)
                break;
            notPrime[i*prime[j]] = 1;
            if(i % prime[j]==0)
                break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> N >> M;
    sieve();
    while(M--)
    {
        int a;
        cin >> a;
        if(notPrime[a])
            cout << "No";
        else
            cout << "Yes";
        cout << endl;
    }
}
