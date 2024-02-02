// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int countGoodTriplets(vector<int> &arr, int a, int b, int c)
{

    int count = 0;
    int n = arr.size();

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                    count++;
            }
        }
    }

    return count;
}

int main()
{
    vi nums{3, 0, 1, 1, 9, 7};
    cout << countGoodTriplets(nums, 7, 2, 3);
}