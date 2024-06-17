// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void updateTree(int idx, int val, int curr, int l, int r, vi &segmentTree)
{
    if (l == r)
    {
        // cout << "before : " << segmentTree[curr] << " curr: " << curr << endl;
        segmentTree[curr] = val;
        // cout << "after : " << segmentTree[curr] << endl;
        return;
    }

    int mid = (l + r) / 2;
    if (idx <= mid)
    {
        // go left
        updateTree(idx, val, 2 * curr + 1, 0, mid, segmentTree);
    }
    else
    {
        updateTree(idx, val, 2 * curr + 2, mid + 1, r, segmentTree);
    }

    segmentTree[curr] = segmentTree[2 * curr + 1] + segmentTree[2 * curr + 2];
}

void buildTree(int i, int l, int r, vi &segmentTree, vi nums)
{
    if (l == r)
    {
        segmentTree[i] = nums[r];
        return;
    }

    int mid = (l + r) / 2;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    buildTree(left, l, mid, segmentTree, nums);
    buildTree(right, mid + 1, r, segmentTree, nums);

    segmentTree[i] = segmentTree[left] + segmentTree[right];
}
void print(vi nums)
{
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    vi nums{3, 2, 1, 7};
    int n = nums.size();
    vi segmentTree((n * 2) - 1);

    buildTree(0, 0, n - 1, segmentTree, nums);
    print(segmentTree);

    // third walay array k index pe jaakr 2 rakhdo
    updateTree(3, 2, 0, 0, n - 1, segmentTree);
    cout << "Updated Segment Tree : ";
    print(segmentTree);
}