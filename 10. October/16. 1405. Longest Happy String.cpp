// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

string solve(priority_queue<pair<int, char>> &pq)
{
    string ans;

    while (!pq.empty())
    {
        int n = ans.size();
        pair<int, char> top = pq.top();
        pq.pop();
        bool pickedFromSecondTop = false;

        if (ans.size() >= 2 && ans[n - 1] == top.second && ans[n - 2] == top.second)
        {
            if (pq.empty())
                return ans;

            pair<int, char> secondTop = pq.top();
            pq.pop();
            ans.push_back(secondTop.second);
            if (secondTop.first - 1 > 0)
                pq.push({secondTop.first - 1, secondTop.second});

            pickedFromSecondTop = true;
        }
        else
        {
            ans.push_back(top.second);
        }

        if (top.first - 1 > 0 && !pickedFromSecondTop)
            pq.push({top.first - 1, top.second});
        else if (top.first > 0 && pickedFromSecondTop)
            pq.push({top.first, top.second});
    }

    return ans;
}

string longestDiverseString(int a, int b, int c)
{
    priority_queue<pair<int, char>> pq;

    if (a > 0)
        pq.push({a, 'a'});
    if (b > 0)
        pq.push({b, 'b'});
    if (c > 0)
        pq.push({c, 'c'});

    string ans = solve(pq);

    return ans;
}

int main()
{
    string ans = longestDiverseString(1, 0, 3);
    cout << ans << endl;
}