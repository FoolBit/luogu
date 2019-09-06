#include <iostream>
#include <cstring>
#include <string>
#include <bitset>
using namespace std;

#define MAXN 8002

int N;
int fzero[MAXN];
int fone[MAXN];
char tree[8002];

void preProcess(string s)
{
    int len = s.length();
    for(int i=1; i<=len; ++i)
    {
        fzero[i] = fzero[i-1];
        fone[i] = fone[i-1];
        if(s[i]=='0')
            ++fzero[i];
        else
            ++fone[i];
    }
}

char judge(int l, int r)
{
    int len = r-l+1;
    if(fzero[r]-fzero[l-1]==len)
        return 'B';
    else if(fone[r]-fone[l-1]==len)
        return 'I';

    return 'F';
}

void buildTree(int l,int r)
{
    if(l==r)
    {
        cout << judge(l,r);
        return;
    }

    int mid = (l+r)>>1;

    buildTree(l, mid);
    buildTree(mid+1, r);

    cout << judge(l, r);
}

int main()
{
    string s;
    cin >> N >> s;
    preProcess(" "+s);
    buildTree(1,s.length());
}