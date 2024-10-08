// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minSwaps(string s)
{
    stack<char> st;

    for (char &ch : s)
    {
        if (ch == '[')
            st.push(ch);
        else if (!st.empty())
            st.pop();
    }

    return (st.size() + 1) / 2;
}