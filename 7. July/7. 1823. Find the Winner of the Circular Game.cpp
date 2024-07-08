// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int findTheWinner(int n, int k)
{

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }

    int start = 0;
    for (int i = 0; i < n - 1; i++)
    {

        int removeIndex = (start + k - 1) % n;
        // nums.erase(remove(nums.begin(), nums.end(), removeVal), nums.end());
        nums.erase(nums.begin() + removeIndex);
        start = (removeIndex + 1) == 5 ? 5 : (removeIndex + 1) % n;
    }

    return nums[0];
}
int main()
{
    int value = findTheWinner(6, 5);
    cout << value << endl;

    // vector<int> nums{1, 2, 3, 4};
    // nums.erase(remove(nums.begin(), nums.end(), 3), nums.end());
    // for (int num : nums)
    //     cout << num << " ";

    // cout << endl;
}