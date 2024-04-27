// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> memo(40, 0);
int tribonacci(int n)
{
    if (memo[n] > 0)
        return memo[n];
    if (n <= 1)
        return n;
    if (n == 2)
        return 1;

    memo[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    return memo[n];
}