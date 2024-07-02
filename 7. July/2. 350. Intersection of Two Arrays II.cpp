// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include 
 
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int n = nums1.size(), m = nums2.size();
    vector<int> answer;

    int i = 0;
    int j = 0;

    while (i < n && j < m)
    {

        if (nums1[i] == nums2[j])
        {
            answer.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else if (nums1[i] > nums2[j])
        {
            j++;
        }
    }

    return answer;
}