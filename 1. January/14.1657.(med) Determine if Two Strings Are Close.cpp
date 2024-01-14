// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool closeStrings(string word1, string word2)
{
    vector<int> v1(26, 0), v2(26, 0), v11(26, 0), v22(26, 0);

    for (int num : word1)
        v1[num - 'a']++, v11[num - 'a'] = 1;

    for (int num : word2)
        v2[num - 'a']++, v22[num - 'a'] = 1;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    return v1 == v2 && v11 == v22;
}