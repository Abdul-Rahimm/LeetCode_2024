// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int Mod = 1e9 + 7;
vector<int> getNSL(vi arr)
{
    int n = arr.size();
    vector<int> result(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (st.empty())
            result[i] = -1;
        else
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            result[i] = st.empty() ? -1 : st.top();
        }

        st.push(i);
    }

    return result;
}
vector<int> getNSR(vi arr)
{
    int n = arr.size();
    vector<int> result(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
            result[i] = n;
        else
        {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            result[i] = st.empty() ? n : st.top();
        }

        st.push(i);
    }

    return result;
}
int sumSubarrayMins(vector<int> &arr)
{
    long long ans = 0;
    int n = arr.size();

    vector<int> NSL = getNSL(arr);
    vector<int> NSR = getNSR(arr);

    for (int i = 0; i < n; i++)
    {
        long long leftSmaller = i - NSL[i];  // smaller elements on the left
        long long rightSmaller = NSR[i] - i; // bigger elements on the right

        long long totalWays = leftSmaller * rightSmaller;

        long long totalSum = arr[i] * totalWays;
        ans = (totalSum + ans) % Mod;
    }

    return ans;
}

int main()
{
    vector<int> nums{3, 1, 2, 4};
    cout << sumSubarrayMins(nums) << endl;
}