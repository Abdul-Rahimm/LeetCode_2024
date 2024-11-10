// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

long long minEnd(int n, int x)
{
    long long num = x;

    for (int i = 1; i < n; i++)
    {
        num = (num + 1) | x;
    }

    return num;
}