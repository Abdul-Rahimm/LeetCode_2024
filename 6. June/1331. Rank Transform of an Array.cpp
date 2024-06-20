// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> arrayRankTransform(vector<int> &arr)
{
    vector<int> copy = arr;

    sort(arr.begin(), arr.end());
    unordered_map<int, int> mp;
    mp[arr[0]] = 1;

    int counter = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
            mp[arr[i]] = counter;
        else
            mp[arr[i]] = ++counter;
    }

    for (int i = 0; i < copy.size(); i++)
    {

        copy[i] = mp[copy[i]];
    }

    return copy;
}

int main()
{
    vi nums{40, 10, 20, 30};
    vi ans = arrayRankTransform(nums);
    print(ans);
}