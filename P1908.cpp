#include <iostream>
#include <cstring>

using namespace std;

#define N 500002
int n;

int tmp[N]; //临时存储的中间数组
long long cnt = 0; //计数

void mergeSort(int *a, int l, int r)
{
    if(l == r)
        return;
    int mid = (l+r)>>1;

    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);

    int i=l;
    int j=mid+1;
    int k=l;

    while(i<=mid && j<=r)
    {
        if(a[i]<=a[j])
        {
            tmp[k++] = a[i++];
        }
        else
        {
            tmp[k++] = a[j++];
            cnt += mid-i+1;
        }
    }

    while(i<=mid)
        tmp[k++] = a[i++];
    while(j<=r)
        tmp[k++] = a[j++];

    for(i=l;i<=r;i++)
        a[i]=tmp[i];
}

int main()
{
    freopen("testdata.in","r",stdin);
    int a[N];
    cin >> n;
    for(int i=0;i<n;++i)
        cin >> a[i];
    mergeSort(a,0,n-1);
    cout << cnt;
}