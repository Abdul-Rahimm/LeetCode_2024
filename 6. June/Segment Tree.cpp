// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

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
    vi nums{1, 2, 3, 4, 5, 6, 7, 8};
    int n = nums.size();
    vi segmentTree((n * 2) - 1);

    buildTree(0, 0, n - 1, segmentTree, nums);
    print(segmentTree);
}