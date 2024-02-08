// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
int solve(int n, int i)
{
    int square = i * i;
    int takeValue = n - square;

    if (takeValue == 0)
        return 1;
    if (takeValue < 0)
        return INT_MAX;

    int take = 1 + solve(takeValue, i);
    int ntake = solve(n, i + 1);

    return min(take, ntake);
}

int numSquares(int n)
{

    return solve(n, 1);
}

int main()
{
    vi nums{5};

    for (int i : nums)
    {
        cout << numSquares(i) << endl;
    }
}