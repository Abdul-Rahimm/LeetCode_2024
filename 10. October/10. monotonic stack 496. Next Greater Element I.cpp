// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mp;
    int n = nums2.size();

    for (int i = 0; i < nums2.size() - 1; i++)
    {
        int curr = nums2[i];

        int j = i;
        while (j < n - 1 && nums2[j + 1] < curr)
        {
            j++;
        }

        if (j != n - 1)
            mp[curr] = nums2[j + 1];
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        nums1[i] = mp.find(nums1[i]) != mp.end() ? mp[nums1[i]] : -1;
    }

    return nums1;
}
