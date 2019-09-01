#include <iostream>

using namespace std;

long long ans[100002];
int n,k;

int main()
{
    cin >> n >> k;
    ans[0] = 1;
    for(int i=1; i<=k; ++i)
    {
        for(int j=0; j<i; ++j)
        {
            ans[i] += ans[j];
            ans[i] %= 100003;
        }
    }

    for(int i=k+1; i<=n; ++i)
    {
        for(int j=i-k;j<i;++j)
        {
            ans[i] += ans[j];
            ans[i] %= 100003;
        }
    }

    cout << ans[n];
}