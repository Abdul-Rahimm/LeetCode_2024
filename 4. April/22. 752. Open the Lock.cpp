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

        // take target[i] and modify it
        bool up = false, down = false;
        string copy = target;
        string copy2 = target;

        while (copy[i] != '0')
        {
            copy[i] = char(src[i] - 1);

            if (st.find(copy) != st.end())
                down = true;
        }
        while (copy[i] != '9')
        {
            copy[i] = char(src[i] + 1);

            if (st.find(copy) != st.end())
                up = true;
        }

        if (up && down)
            return -1;

        // even before this u want to make sure if its possible
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
    vector<string> deadends{"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    cout << openLock(deadends, "8888");
    vector<string> deadends2{"0201", "0101", "0102", "1212", "2002"};
    cout << openLock(deadends2, "0202");
    vector<string> deadends3{"8888"};
    cout << openLock(deadends3, "0009");
}