// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool parseBoolExpr(string s)
{
    stack<char> st;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {

        if (s[i] == ',')
            continue;

        if (s[i] == ')')
        {
            bool f = false;
            bool t = false;

            while (st.top() != '(')
            {
                char curr = st.top();
                st.pop();
                if (curr == 'f')
                    f = true;
                else if (curr == 't')
                    t = true;
            }
            st.pop();

            char toPut;
            if (st.top() == '|')
            {
                toPut = t == true ? 't' : 'f';
            }
            else if (st.top() == '&')
            {
                toPut = f == true ? 'f' : 't';
            }
            else if (st.top() == '!')
            {
                toPut = f == true ? 't' : 'f';
            }
            st.pop();
            st.push(toPut);
            continue;
        }

        st.push(s[i]);
    }

    if (st.top() == 'f')
        return false;
    else
        return true;
}