// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minAddToMakeValid(string s)
{
    stack<char> st;

    for (char i : s)
    {
        if (i == '(')
        {
            st.push(i);
        }
        else if (!st.empty() && st.top() == '(')
        {
            st.pop();
        }
        else
        {
            st.push(i);
        }
    }

    return st.size();
}