#include <iostream>

using namespace std;

int divide(int n,int k,int line)
{
    if(k==0)
        return 0;
    if(n < line)
        return 0;
    if(k==1)
        return 1;

    int ans=0;
    int MAX = n-k+1;
    for(int i=line;i<=MAX;++i)
    {
        ans += divide(n-i,k-1,i);
    }
    return ans;

}

int main()
{
    int n,k;
    cin >> n >> k;
    cout << divide(n,k,1);
}