// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> v1, v2;
int n;

unordered_map<string, int> mp;

int solve(int i, int k)
{
    if (k <= 0 || i > n)
        return 0;

    string key = to_string(i) + " " + to_string(k);
    if (mp.find(key) != mp.end())
        return mp[key];

    int take = v1[i] + solve(i + 1, k - 1);
    int ntake = v2[i] + solve(i + 1, k);

    return mp[key] = max(take, ntake);
}

int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
{
    v1 = reward1;
    v2 = reward2;
    n = reward1.size();

    return solve(0, k);
}

int main()
{
    vi nums{1, 1, 3, 4}, nums2{4, 4, 1, 1};
    int k = 2;

    cout << miceAndCheese(nums, nums2, k) << endl;
}