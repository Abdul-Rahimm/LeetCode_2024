// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int nthUglyNumber(int n)
{

    vector<int> nums{1, 2, 3, 4, 5};
    set<int> st(nums.begin(), nums.end());

    for (int i = 1; i <= n; i++)
    {

        int current = nums[i];

        if (st.find(current * 2) == st.end())
        {
            st.insert(current * 2);
            nums.push_back(current * 2);
        }
        if (st.find(current * 3) == st.end())
        {
            st.insert(current * 3);
            nums.push_back(current * 3);
        }
        if (st.find(current * 5) == st.end())
        {
            st.insert(current * 5);
            nums.push_back(current * 5);
        }
    }

    sort(nums.begin(), nums.end());
    print(nums);

    return nums[n - 1];
}

int main()
{
    cout << nthUglyNumber(27) << endl;
}