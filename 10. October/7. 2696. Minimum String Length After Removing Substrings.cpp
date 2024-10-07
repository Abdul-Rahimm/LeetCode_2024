// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minLength(string s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (!st.empty() && ((s[i] == 'B' && st.top() == 'A') || (s[i] == 'D' && st.top() == 'C')))
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    return st.size(); //
}