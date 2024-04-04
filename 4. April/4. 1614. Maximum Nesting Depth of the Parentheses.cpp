// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int maxDepth(string s)
{
    stack<char> st;
    int count = 0;

    for (char i : s)
    {
        if (i == '(')
        {
            st.push('a');
        }
        else if (i == ')')
        {
            st.pop();
        }

        count = max(count, int(st.size()));
    }

    return count;
}