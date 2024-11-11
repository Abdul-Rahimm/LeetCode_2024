// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool isPrime(int i)
{
    for (int j = 2; j <= (i + 1) / 2; j++)
    {
        if (i % j == 0)
            return false;
    }
    return true;
}
bool primeSubOperation(vector<int> &nums)
{
    int n = nums.size();
    vector<int> primes;
    int limit = *max_element(nums.begin(), nums.end());
    bool prime[1000];
    fill(prime, prime + 1000, false);

    for (int i = 2; i <= limit; i++)
    {
        if (isPrime(i))
            prime[i] = true;
    }

    for (int i = n - 2; i >= 0; i--)
    { // O(n)
        if (nums[i] < nums[i + 1])
        {
            continue;
        }
        // nums[i] >= nums[i+1]
        // decrease nums[i] atleast less than nums[i+1]
        // check prime numbers less than nums[i]
        for (int p = 2; p < nums[i]; p++)
        { // O(max of nums)
            if (!prime[p])
            {
                continue;
            }

            if (nums[i] - p < nums[i + 1])
            {
                nums[i] -= p;
                break;
            }
        }

        if (nums[i] >= nums[i + 1])
        {
            return false;
        }
    }

    return true;
}
