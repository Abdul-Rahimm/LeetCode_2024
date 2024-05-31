// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> singleNumber(vector<int> &nums)
{
    int n = nums.size();

    int first = 0, second = 0; // two groups
    long long allXor = 0;

    // 1. find the xor of all numbers
    for (int i : nums)
        allXor ^= i; // the xor of all nums in array

    int mask = allXor & -allXor; // sneaky way to find mask. wrna right shift untill number becomes odd

    for (int i : nums)
    {
        if (mask & i)
            first ^= i; // belongs to first group
        else
            second ^= i;
    }

    return {first, second};
}

void print(vi nums)
{
    for (int i : nums)
        cout << i << " ";
    cout << endl;
}
int main()
{
    vector<int> nums{1, 2, 1, 3, 2, 5};
    vector<int> ans = singleNumber(nums);
    print(ans);
}