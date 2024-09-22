// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int Count(long curr, long next, int n)
{
    int countNum = 0;

    while (curr <= n)
    {
        countNum += (next - curr);

        curr *= 10;
        next *= 10;

        next = min(next, long(n + 1));
    }

    return countNum;
}
int findKthNumber(int n, int k)
{
    int curr = 1;
    k--;

    while (k > 0)
    {
        int count = Count(curr, curr + 1, n);

        if (count <= k)
        {
            curr++;
            k -= count;
        }
        else
        {
            curr *= 10;
            k -= 1;
        }
    }

    return curr;
}
