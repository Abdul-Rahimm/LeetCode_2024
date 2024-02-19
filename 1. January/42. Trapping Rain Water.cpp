// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int trap(vector<int> &height)
{
    int n = height.size();
    int ans = 0;

    vector<int> left(n, height[0]);
    vector<int> right(n, height[n - 1]);

    int number = height[0];
    for (int i = 1; i < n; i++)
    {
        number = max(number, height[i - 1]);

        left[i] = number;
    }

    number = height[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        number = max(number, height[i - 1]);

        right[i] = number;
    }

    for (int i = 1; i < n - 1; i++)
    {
        number = min(left[i], right[i]) - height[i];

        ans += number;
    }

    return ans;
}

int main()
{
    vi nums{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(nums) << endl;
}