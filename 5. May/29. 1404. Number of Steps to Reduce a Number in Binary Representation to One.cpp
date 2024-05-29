// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool isEven(string s)
{
    return s[s.size() - 1] == '0';
}
void allOnes(string &s)
{
    bool isAllOnes = true;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            isAllOnes = false;
            break;
        }
    }

    string str;
    if (isAllOnes)
    {
        str = "0";
        for (int i = 0; i < s.size(); i++)
            str += s[i];

        s = str; // appended 0 at the beginning
    }
}
void shiftAllRight(string &s)
{
    int size = s.size();

    for (int i = size - 2; i >= 0; i--)
    {
        s[i + 1] = s[i];
    }

    s[0] = '0';
}
void moveLSBleft(string &s)
{
    int i = s.size() - 1;
    int j = i - 1;
    bool cont;
    do
    {
        cont = s[j] == '1' ? true : false;
        s[i] = '0';
        s[j] = '1';
        i--;
        j--;
    } while (cont);
}
bool isReachedOne(string s)
{
    int size = s.size();

    bool status = false;

    for (int i = 0; i < size - 1; i++)
    {
        if (s[i] == '1')
            return false;
    }

    if (s[size - 1] == '0')
        return false;

    return true;
}

int numSteps(string s)
{
    int steps = 0;
    allOnes(s); // if all ones then append a 0 at the start

    while (isReachedOne(s) == false)
    {
        steps++;

        if (isEven(s))
        {
            shiftAllRight(s);
            cout << s << endl;
        }
        else
        {
            moveLSBleft(s);
            cout << s << endl;
        }
    }

    return steps;
}
int main()
{
    string s = "11111000111";
    int ans = numSteps(s);
    cout << ans << endl;
}