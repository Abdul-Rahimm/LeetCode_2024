// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int heightChecker(vector<int> &heights)
{
    int i = 0, j = 0;
    int n = heights.size();
    int result = 0;
    vector<int> sorted(heights.begin(), heights.end());
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < n; i++)
    {
        if (sorted[i] != heights[i])
            result++;
    }

    return result;
}