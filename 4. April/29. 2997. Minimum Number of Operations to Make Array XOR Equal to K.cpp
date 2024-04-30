// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minOperations(vector<int> &nums, int k)
{
    int totalXor = 0;

    for (int i : nums)
        totalXor ^= i;

    int diff = totalXor ^ k;

    return __builtin_popcount(diff);
}