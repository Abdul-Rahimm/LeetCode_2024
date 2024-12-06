// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        int n = s.size();
        stack<char> st;

        for (int i = n - 1; i >= 0; i--)
        {
            st.push(s[i]);
        }

        string ans;

        int index = 0;
        int i = 0;
        while (!st.empty())
        {

            if (i < spaces.size() && index == spaces[i])
            {
                i++;
                ans.push_back(' ');
                continue;
            }

            ans.push_back(st.top());
            st.pop();
            index++;
        }

        return ans;
    }
};