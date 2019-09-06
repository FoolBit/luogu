#include <iostream>
#include <cstring>

using namespace std;

int T,M;
int f[1002];

void zeroOnePack(int weight,int value)
{
    for(int i=T; i>=weight; --i)
        f[i] = max(f[i], f[i-weight]+value);
}

int main()
{
    cin >> T >> M;
    while(M--)
    {
        int w,v;
        cin >> w >> v;
        zeroOnePack(w, v);
    }
    cout << f[T];
}