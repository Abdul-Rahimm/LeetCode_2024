// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void swap(int i, int j, string &s)
{
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}
int maximumSwap(int num)
{
    priority_queue<pair<int, int>> pq; // no, index
    if (num < 10)
        return num;

    string s = to_string(num);
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        pq.push({s[i], i});
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] < pq.top().first)
        {
            // index compare
            while (pq.top().second < i)
            {
                pq.pop();
            }
        }
        print(pq);

        if (pq.top().first == s[i])
            continue;

        swap(pq.top().second, i, s);
        break;
    }

    return stoi(s);
}

int main()
{
    int num = 98368;
    cout << maximumSwap(num) << endl; // 7236
    return 0;
}