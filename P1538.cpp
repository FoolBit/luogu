#include <iostream>
#include <string>

using namespace std;

int k;
string s;

void handle(char str, int line);

int main()
{
    ios::sync_with_stdio(0);

    cin >> k >> s;
    int n = s.length();

    int nlines = 2 * k + 3;
    for(int line=0; line < nlines; ++line)
    {
        handle(s[0], line);
        for(int i=1; i<n; ++i)
        {
            cout << ' ';
            handle(s[i], line);
        }
        cout << endl;

    }
}

int segment(int line)
{
    if(line == 0)
        return 0;
    if(1 <= line && line < k+1)
        return 1;
    if(k+1 == line)
        return 2;
    if(k+1 < line && line < 2*k+2)
        return 3;
    return 4;
}

void print(int type)
{
    // 0:space 1:horizon line 2:left line 3:right line 4:both line
    if(type == 0)
    {
        cout << ' ';
        for(int i=0; i<k; ++i)
            cout << ' ';
        cout << ' ';
    }
    else if(type == 1)
    {
        cout << ' ';
        for(int i=0; i<k; ++i)
            cout << '-';
        cout << ' ';
    }
    else if(type == 2)
    {
        cout << '|';
        for(int i=0; i<k; ++i)
            cout << ' ';
        cout << ' ';
    }
    else if(type == 3)
    {
        cout << ' ';
        for(int i=0; i<k; ++i)
            cout << ' ';
        cout << '|';
    }
    else if(type == 4)
    {
        cout << '|';
        for(int i=0; i<k; ++i)
            cout << ' ';
        cout << '|';
    }
}

void handle(char str, int line)
{
    int num = str - '0';

    int seg = segment(line);

    switch(num)
    {
        case 1:
            if(seg == 0 || seg == 2 || seg == 4)
                print(0);
            else
                print(3);
            break;

        case 2:
            if(seg == 0 || seg == 2 || seg == 4)
                print(1);
            else if(seg == 1)
                print(3);
            else
                print(2);
            break;

        case 3:
            if(seg == 0 || seg == 2 || seg == 4)
                print(1);
            else
                print(3);
            break;

        case 4:
            if(seg == 0 || seg == 4)
                print(0);
            else if(seg == 2)
                print(1);
            else if(seg == 1)
                print(4);
            else if(seg == 3)
                print(3);
            break;

        case 5:
            if(seg == 0 || seg == 2 || seg == 4)
                print(1);
            else if(seg == 1)
                print(2);
            else
                print(3);
            break;

        case 6:
            if(seg == 0 || seg == 2 || seg == 4)
                print(1);
            else if(seg == 1)
                print(2);
            else
                print(4);
            break;

        case 7:
            if(seg == 0)
                print(1);
            else if(seg == 1 || seg == 3)
                print(3);
            else
                print(0);
            break;

        case 8:
            if(seg == 0 || seg == 2 || seg == 4)
                print(1);
            else
                print(4);
            break;

        case 9:
            if(seg == 0 || seg == 2 || seg == 4)
                print(1);
            else if(seg == 1)
                print(4);
            else
                print(3);
            break;

        case 0:
            if(seg == 0 || seg == 4)
                print(1);
            else if(seg == 2)
                print(0);
            else
                print(4);
    }
}