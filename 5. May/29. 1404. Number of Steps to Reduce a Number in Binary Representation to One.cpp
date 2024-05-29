// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
bool isEven_outdated(int num)
{
    return num % 2 == 0;
}
int numSteps_failed(string s)
{
    int size = s.size();
    int value = 0;
    int power = 1;

    for (int i = size - 1; i >= 0; i--)
    {
        int number = int(s[i] - 48);

        value += power * number;

        power *= 2;
    }

    int steps = 0;

    while (value != 1)
    {
        if (isEven_outdated(value))
        {
            value /= 2;
        }
        else
        {
            value += 1;
        }

        steps++;
    }

    return steps;
}
// --------------------------------------------------------------------------
bool isEven(string s)
{
    return s[s.size() - 1] == '0';
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
int numSteps(string s)
{
    int steps = 0;

    while (stoi(s) != 1)
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
    string s = "1101";
    int ans = numSteps(s);
    cout << ans << endl;
}