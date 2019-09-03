#include <iostream>

using namespace std;

int l,r;

int main()
{
    char c;
    while(cin >> c)
    {
        if(c=='(')
            ++l;
        if(c==')')
        {
            if(l>0)
            {
                --l;
            }
            else
            {
                ++r;
                break;
            }
        }
        if(c=='@')
            break;
    }
    if(l||r)
        cout << "NO";
    else
        cout << "YES";
}
