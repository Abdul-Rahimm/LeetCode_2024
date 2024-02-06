// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<string> removeAnagrams(vector<string> &words)
{
    int n = words.size();
    vector<string> ans;

    ans.push_back(words[0]);
    // sorting makes things easy here.

    for (int i = 1; i < n; i++)
    {
        string wordFirst = words[i];
        string wordSecond = words[i - 1];

        sort(wordFirst.begin(), wordFirst.end());
        sort(wordSecond.begin(), wordSecond.end());

        if (wordFirst == wordSecond)
            continue;

        ans.push_back(words[i]);
    }

    return ans;
}
