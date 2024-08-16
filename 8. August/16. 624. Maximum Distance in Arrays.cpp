// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

typedef pair<int, int> P;

int maxDistance(vector<vector<int>> &arrays)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<P, vector<P>> maxHeap;
    priority_queue<P, vector<P>, greater<P>> minHeap;

    int n = arrays.size();
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arrays[i][0]);
        minHeap.push({arrays[i][0], i + 1});

        maxi = max(maxi, arrays[i][arrays[i].size() - 1]);
        maxHeap.push({arrays[i][arrays[i].size() - 1], i + 1});
    }

    // print(maxHeap);
    // print(minHeap);

    P minHeapTop = minHeap.top();
    minHeap.pop();
    P maxHeapTop = maxHeap.top();
    maxHeap.pop();

    if (minHeapTop.second != maxHeapTop.second)
    {
        // cout << "Min Heap first " << minHeapTop.first << " " << minHeapTop.second << endl;
        // cout << "max Heap first " << maxHeapTop.first << " " << maxHeapTop.second << endl;

        return maxi - mini;
    }
    else
    {
        // check both cases
        P minHeapSecond = minHeap.top();
        P maxHeapSecond = maxHeap.top();

        // cout << "Min Heap second " << minHeapSecond.first << " " << minHeapSecond.second << endl;
        // cout << "max Heap second " << maxHeapSecond.first << " " << maxHeapSecond.second << endl;

        int first = maxHeapSecond.first - minHeapTop.first;
        int second = maxHeapTop.first - minHeapSecond.first;

        return max(first, second);
    }

    return 0;
}

int main()
{

    vii nums{{1, 5}, {3, 4}};
    cout << maxDistance(nums) << endl;
}