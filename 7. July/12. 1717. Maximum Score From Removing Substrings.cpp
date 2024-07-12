// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void y_Greater_x(stack<char> &st, char &i, int &sum, int &value)
{
    if (!st.empty() && i == 'a' && st.top() == 'b')
    {
        st.pop();
        sum += value;
    }
    else
    {
        st.push(i);
    }
}

void x_Greater_y(stack<char> &st, char &i, int &sum, int &value)
{
    if (!st.empty() && i == 'b' && st.top() == 'a')
    {
        st.pop();
        sum += value;
    }
    else
    {
        st.push(i);
    }
}

int remove(string &s, string chr, int value, bool isFirstPass)
{
    // bool isFirstPass because we need to update the string after first pass for the second pass

    stack<char> st;
    int sum = 0;

    for (char i : s)
    {
        if (chr == "ba")
            y_Greater_x(st, i, sum, value);
        else
            x_Greater_y(st, i, sum, value);
    }

    if (isFirstPass)
    {
        // update the string for the second Pass
        string updatedString;

        while (st.empty() != true)
        {
            updatedString.push_back(st.top());
            st.pop();
        }
        reverse(updatedString.begin(), updatedString.end());
        s = updatedString;
        cout << s << endl;
    }

    return sum;
}

int maximumGain(string s, int x, int y)
{
    string firstPass = x > y ? "ab" : "ba";
    string secondPass = firstPass == "ab" ? "ba" : "ab";

    int major = x > y ? x : y;
    int minor = major == x ? y : x;

    int afterFirstPass = remove(s, firstPass, major, true);
    int afterSecondPass = remove(s, secondPass, minor, false);

    return afterFirstPass + afterSecondPass;
}

int main()
{
    string s = "cdbcbbaaabab";
    cout << maximumGain(s, 4, 5) << endl;
}