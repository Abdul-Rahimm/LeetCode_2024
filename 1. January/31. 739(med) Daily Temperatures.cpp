// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> dailyTemperatures(vector<int> &t)
{
    int n = t.size();

    vector<int> ans(n, 0);

    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && t[st.top()] < t[i])
        {
            st.pop();
        }

        if (st.empty())
            ans[i] = 0;
        else
            ans[i] = st.top() - i;

        st.push(i);
    }

    return ans;
}

int main()
{
    vi nums{73, 74, 75, 71, 69, 72, 76, 73};
    vi ans = dailyTemperatures(nums);

    for (int i : ans)
    {
        cout << i << " ";
    }
}