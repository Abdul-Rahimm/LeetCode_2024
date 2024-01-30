// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

stack<int> s1;
int ans = 0;

void applyOperation(string i)
{
    int result;
    int first = s1.top();
    s1.pop();
    int second = s1.top();
    s1.pop();

    cout << second << " " << i << " " << first << endl;

    if (i == "+")
        result = first + second;
    else if (i == "-")
        result = second - first;
    else if (i == "*")
        result = second * first;
    else
        result = second / first;

    ans = result;
    cout << ans << endl;
    s1.push(result);
}

int evalRPN(vector<string> &tokens)
{
    for (string i : tokens)
    {
        int num = 0;

        if (i == "+" || i == "-" || i == "*" || i == "/")
        {
            applyOperation(i);
            continue;
        }

        // for extracting number

        bool negative = i.front() == '-' ? true : false;
        for (char ch : i)
        {
            if (ch == '-')
                continue;

            num *= 10;
            num = num + (int(ch) - 48);
        }

        if (negative)
            num *= -1;

        if (tokens.size() == 1)
            return num;

        s1.push(num);
    }

    return ans;
}

int main()
{
    vector<string> tokens{"20"};
    // vector<string> tokens{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    cout << evalRPN(tokens) << endl;
}