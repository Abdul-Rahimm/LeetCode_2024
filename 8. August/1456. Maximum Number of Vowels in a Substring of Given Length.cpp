// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool isVowel(char i)
{
    return i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u';
}

int maxVowels(string s, int k)
{

    int n = s.size();
    int i = 0;
    int j = 0;
    int count = 0, ans = 0;

    while (j < n)
    {
        if (j - i == k)
        {
            if (isVowel(s[i]) == true)
                count--;

            i++;
        }

        if (isVowel(s[j]) == true)
        {
            count++;
            ans = max(ans, count);
        }

        j++;
    }

    return ans;
}