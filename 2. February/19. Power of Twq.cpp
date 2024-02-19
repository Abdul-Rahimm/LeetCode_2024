#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    if (n % 2 == 1 && n != 1)
        return false;

    while (n > 2)
    {
        int m = n % 2;
        n = n / 2;
        if (m == 1)
            return false;
    }
    return true;
}
bool isPowerOfTwo__builtin_popcount(int n)
{
    if (n <= 0)
        return false;

    int count = __builtin_popcount(n);

    return count == 1;
}

int main()
{
    fastio;
    // code goes here
    return 0;
}