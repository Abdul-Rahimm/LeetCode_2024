// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"

using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pr;

int longestSubarray_failed(vector<int> &nums, int limit)
{
    int i = 0, j = 0;
    int n = nums.size();
    int maxLength = 1;

    while (i < n && j < n)
    {

        int diff = abs(nums[i] - nums[j]);
        if (diff <= limit)
            maxLength = max(maxLength, j - i + 1);

        if (diff > limit)
            i++;

        j++;
    }

    return maxLength;
}

int longestSubarray(vector<int> &nums, int limit)
{
    int i = 0, j = 0;
    int n = nums.size();
    int maxLength = 0;

    priority_queue<pr, vector<pr>, greater<pr>> minHeap;
    priority_queue<pr> maxHeap;

    while (j < n)
    {
        minHeap.push({nums[j], j});
        maxHeap.push({nums[j], j});

        int diff = abs(minHeap.top().first - maxHeap.top().first);
        if (diff > limit)
        {
            int newIndex = minHeap.top().second < maxHeap.top().second ? minHeap.top().second : maxHeap.top().second;
            i = newIndex + 1;

            cout << minHeap.top().second << " " << maxHeap.top().second << endl;
            while (minHeap.top().second < i)
            {
                minHeap.pop();
            }
            while (maxHeap.top().second < i)
            {
                maxHeap.pop();
            }
        }

        maxLength = max(maxLength, j - i + 1);

        j++;
    }

    return maxLength;
}

int main()
{
    vi nums{8, 2, 4, 7};
    cout << longestSubarray(nums, 4) << endl;
}