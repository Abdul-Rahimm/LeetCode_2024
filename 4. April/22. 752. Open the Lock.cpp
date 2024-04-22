// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int openLock(vector<string> &deadends, string target)
{
    int ans = 0;

    unordered_set<string> st;
    for (string i : deadends)
    {
        st.insert(i);
    }

    // make tis equal to taret
    string src = "0000";

    for (int i = 0; i < 4; i++)
    {
        while (src[i] != target[i])
        {
            if (target[i] - src[i] <= 5)
            {
                src[i] = char(src[i] + 1);
                ans++;
            }
            else
            {
                if (src[i] == '0')
                    src[i] = '9';
                else
                {
                    src[i] = char(src[i] - 1);
                }

                ans++;
            }

            if (st.find(src) != st.end())
                ans += 2;
        }
    }

    return ans;
}

int main()
{
    vector<string> deadends{"0201", "0101", "0102", "1212", "2002"};
    cout << openLock(deadends, "0009");
}