#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
int solve_min(long long n)
{
    if (n == 0)
        return 0;

    long long four, six;

    if (n - 4 >= 0)
        four = 1 + solve_min(n - 4);

    if (n - 6 >= 0)
        six = 1 + solve_min(n - 6);

    return min(four, six);
}
int solve_max(long long n)
{
    if (n == 0)
        return 0;

    long long four = 0, six = 0;

    if (n - 4 >= 0)
        four = 1 + solve_max(n - 4);

    if (n - 6 >= 0)
        six = 1 + solve_max(n - 6);

    return max(four, six);
}

int main()
{
    fastio;
    int t = 1;
    // cin >> t;

    while (t--)
    {

        long long n;
        cin >> n;

        if (n % 2 != 0)
        {
            cout << -1 << endl;
            continue;
        }

        long long x = solve_min(n);
        long long y = solve_max(n);
        cout << x << " " << y << endl;
    }
    return 0;
}