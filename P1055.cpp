#include <iostream>
#include <string>
using namespace std;

char id[] = {'0','1','2','3','4','5','6','7','8','9','X'};

int main()
{
    string ISBN;
    cin >> ISBN;
    int a = 0;
    int cnt = 1;

    for(int i=0; i<11; ++i)
    {
        if(ISBN[i]!='-')
        {
            a += (ISBN[i] - '0') * cnt;
            ++cnt;
        }
    }

    a %= 11;
    if(ISBN[12] == id[a])
        cout << "Right";
    else
    {
        ISBN[12] = id[a];
        cout << ISBN;
    }
}