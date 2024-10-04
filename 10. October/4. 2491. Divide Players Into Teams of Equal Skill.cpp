// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

long long dividePlayers(vector<int> &skill)
{
    sort(skill.begin(), skill.end());

    int i = 1, j = skill.size() - 2;
    int eachTeam = skill[0] + skill[skill.size() - 1];
    long long ans = skill[0] * skill[skill.size() - 1];

    while (i < j)
    {
        if (skill[i] + skill[j] != eachTeam)
            return -1;

        ans += skill[i] * skill[j];

        i++;
        j--;
    }

    return ans;
}