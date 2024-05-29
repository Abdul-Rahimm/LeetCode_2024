// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
bool isEven(int num)
{
    return num % 2 == 0;
}
int numSteps(string s)
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
        if (isEven(value))
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

int main()
{
    string s = "1101";
    cout << numSteps(s) << endl;
}