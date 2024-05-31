// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int duplicateNumbersXOR(vector<int> &nums)
{

    vector<int> freq(51, 0);

    for (int i : nums)
        freq[i]++;

    int allXor = 0;

    for (int i = 0; i < freq.size(); i++)
    {

        if (freq[i] == 2)
            allXor ^= i;
    }

    return allXor;
}

int main()
{
    vector<int> nums{1, 2, 1, 4};
    cout << duplicateNumbersXOR(nums) << endl;
}