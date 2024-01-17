// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int splitNum(int num)
{
    priority_queue<int, vi, greater<int>> st; // min heap use greater

    while (num > 0)
    {
        st.push(num % 10);
        num /= 10;
    }

    int num1 = 0, num2 = 0;
    int count = 0;

    while (!st.empty())
    {
        if (count % 2 == 0)
        {
            num1 *= 10;
            num1 += st.top();
        }
        else
        {
            num2 *= 10;
            num2 += st.top();
        }

        st.pop();
        count++;
    }

    return num1 + num2;
}

int main()
{
    splitNum(4325);
}