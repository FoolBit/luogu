#include <iostream>
#include <string>

using namespace std;

int isNum(char a)
{
    if(a >= '0' && a <= '9')
        return 1;
    else
        return 0;
}
void split(string num);
string inverse(string num);

int main()
{
    string num;
    cin >> num;
    split(num);
}

void split(string num)
{
    auto last = num.begin();
    auto iter = num.begin();
    bool flag = 0;
    for(; iter!=num.end(); ++iter )
    {
        if(isNum(*iter))
            continue;
        if(*iter == '.')
            flag = 1;
        cout << inverse(string(last, iter));
        cout << *iter;
        last = iter + 1;
    }
    if(flag)
    {
        string str = string(last, iter);
        str = inverse(string(str.rbegin(), str.rend()));
        cout << string(str.rbegin(), str.rend());
    }
    else if(last!=iter)
        cout << inverse(string(last, iter));
}

string inverse(string num)
{
    string str(num.rbegin(), num.rend());

    // get rid of 0
    auto iter = str.begin();
    for(; iter!=str.end(); ++iter)
        if(*iter != '0')
            break;

    if(iter == str.end())
        --iter;

    return string(iter, str.end());

}