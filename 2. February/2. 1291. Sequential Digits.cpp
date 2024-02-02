// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> sequentialDigits(int low, int high)
{
    queue<int> q;
    vector<int> ans;

    // insert 1-8 into queue
    for (int i = 1; i < 9; i++)
    {
        q.push(i);
    }

    while (!q.empty())
    {

        int qFront = q.front();
        q.pop();

        if (qFront >= low && qFront <= high)
            ans.push_back(qFront);

        int lastDigit = qFront % 10;
        if (lastDigit == 9 || qFront > high)
            continue; // no processing for this.

        int addDigit = lastDigit + 1;
        int newDigit = qFront * 10 + addDigit;

        q.push(newDigit);
    }

    return ans;
}
