// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

string compressedString(string word)
{
    int i = 0;
    int count = 1;
    string ans = "";

    while (i < word.size())
    {

        if (word[i] == word[i + 1] && count < 9)
        {
            count++;
        }
        else
        {
            ans += to_string(count) + word[i];
            count = 1;
        }

        i++;
    }

    return ans;
}