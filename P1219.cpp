#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int N;
int cnt;
int ans[3][14];

int pieces[14];
int cols[14];

void dfs(int row);

bool judge(int x, int y)
{
    for(int i=1; i<x; ++i)
        if(abs(x-i) == abs(y-pieces[i]))
            return 0;

    return 1;
}

void print()
{
    for(int i=0; i<3; ++i)
    {
        cout << ans[i][0];
        for(int j=1; j<N; ++j)
            cout << " " << ans[i][j];
        cout << endl;
    }
}

string num2str(int n)
{
    string str="";
    if(n==0)
        return "0";
    while(n)
    {
        str = char('0' + n%10) + str;
        n /= 10;
    }

    return str;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> N;

    dfs(1);

    print();

    cout << cnt;
}

void dfs(int row)
{
    for(int i=1; i<=N; ++i)
    {
        if(!cols[i] && judge(row,i))
        {
            cols[i] = 1;
            pieces[row] = i;

            if(row!=N)
            {
                dfs(row + 1);
            }
            else
            {
                if(cnt < 3)
                {
                    for(int j=1; j<=N; ++j)
                        ans[cnt][j-1] = pieces[j];
                }
                ++cnt;
            }
            cols[i] = 0;

        }
    }
}
