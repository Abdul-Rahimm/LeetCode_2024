// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    int t[101][101];

    int countSteps(int i, int hourIndex, string ring)
    {
        int distance = abs(i - hourIndex);
        int wrapAround = ring.size() - distance;

        return min(distance, wrapAround);
    }

    int solve(int hourIndex, int kIndex, string ring, string key)
    {

        if (kIndex >= key.size())
            return 0; // now u need to do 0 steps

        if (t[hourIndex][kIndex] != -1)
            return t[hourIndex][kIndex];

        int result = INT_MAX;

        for (int i = 0; i < ring.size(); i++)
        {
            int totalsteps = INT_MAX;
            if (ring[i] == key[kIndex])
                totalsteps = countSteps(i, hourIndex, ring) + 1 + solve(i, kIndex + 1, ring, key);

            result = min(result, totalsteps);
        }

        return t[hourIndex][kIndex] = result;
    }

    int findRotateSteps(string ring, string key)
    {
        memset(t, -1, sizeof(t));
        return solve(0, 0, ring, key);
    }
};