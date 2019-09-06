#include <iostream>
#include <cstring>

using namespace std;

int f[30002];
int N,M;

int main()
{
    ios::sync_with_stdio(0);
    cin >> N >> M;
    int a;
    f[0] = 1;
    while(N--)
    {
        cin >> a;
        for(int i=M; i>=a; --i)
        {
            if(f[i-a])
                f[i]+=f[i-a];
        }
    }
    cout << f[M];
}