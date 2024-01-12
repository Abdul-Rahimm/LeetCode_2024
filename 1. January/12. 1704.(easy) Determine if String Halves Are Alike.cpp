// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool isVowel(char i)
{
    i = tolower(i);

    if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
        return true;

    return false;
}

bool halvesAreAlike(string s)
{

    int i = 0, j = s.size() - 1;
    int count = 0;

    while (i < j)
    {
        if (isVowel(s[i]))
            count++;
        if (isVowel(s[j]))
            count--;

        i++;
        j--;
    }

    if (count == 0)
        return true;

    return false;
}