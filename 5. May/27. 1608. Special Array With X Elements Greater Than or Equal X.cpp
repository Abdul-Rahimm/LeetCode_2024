// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int specialArray(vector<int> &nums)
{
    vector<int> freq(1001, 0);

    int highest = 0; // for iterating till the highest number

    for (int point : nums)
    {
        highest = max(highest, point);

        for (int i = 0; i <= point; i++)
        {
            freq[i]++;
        }
    }

    int ans = -1;
    for (int i = 0; i <= highest; i++)
    {
        if (freq[i] == i)
            ans = i;
    }

    return ans;
}