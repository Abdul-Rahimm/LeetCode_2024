// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int singleNumber(vector<int> &nums)
{

    int allXor = 0;

    for (int i : nums)
        allXor ^= i;

    return allXor;
}