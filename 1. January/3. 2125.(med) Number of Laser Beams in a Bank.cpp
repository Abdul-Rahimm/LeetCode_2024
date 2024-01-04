// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int numberOfBeams(vector<string> &bank)
{
    int n = bank.size();
    int m = bank[0].size();
    vector<int> nums(n, 0);
    stack<int> st;

    int count = 0;
    for (string i : bank)
    {
        for (char j : i)
        {
            if (j == '1')
                nums[count] = nums[count] + 1;
        }

        if (nums[count] > 0)
            st.push(nums[count]);

        count++;
    }

    int ans = 0;
    while (st.size() > 1)
    {
        int top = st.top();
        st.pop();
        ans += top * st.top();
    }

    return ans;
}

int main()
{
    vector<string> bank{"011001", "000000", "010100", "001000"};
    cout << numberOfBeams(bank) << endl;
}