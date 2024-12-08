// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool isPossible(int mid, vector<int> &candies, long long k, long long sum)
{
    int ops = 0;
    for (int i = 0; i < candies.size(); i++)
    {
        ops += candies[i] / mid;
    }

    return ops >= k;
}

int maximumCandies(vector<int> &candies, long long k)
{
    int left = 0;
    int right = *min_element(candies.begin(), candies.end());
    long long sum = 0;

    for (int i : candies)
        sum += i;

    if (sum < k)
        return 0;

    while (left + 1 < right)
    {
        int mid = (left + right) / 2;

        if (mid == 0)
            return 0;

        if (isPossible(mid, candies, k, sum))
        {
            left = mid;
            cout << left << " " << right << endl;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left;
}

int main()
{
    vector<int> candies{5, 8, 6};
    long long k = 3;

    cout << maximumCandies(candies, k) << endl;
}