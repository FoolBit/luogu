#include <iostream>
#include <algorithm>

using namespace std;

int f[100001];
int A,B;
int MAX;

bool found(int length)
{
    int cnt=1;
    int i=0,j=1;

    while(j<A)
    {
        if(f[j]-f[i]<length)
        {
            ++j;
            continue;
        }

        ++cnt;
        if(cnt == B)
            return 1;
        i=j;
        ++j;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);

    cin >> A >> B;
    for(int i=0; i<A; ++i) cin >> f[i];
    sort(f,f+A);

    int l=0;
    int r=f[A-1]-f[0];

    while(l<=r)
    {
        int mid = (l+r)>>1;
        if(found(mid))
        {
            MAX = max(mid,MAX);
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout << MAX;
}