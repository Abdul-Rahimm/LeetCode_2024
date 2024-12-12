// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int> pq(gifts.begin(), gifts.end());

        long long ans = 0;
        int n = gifts.size();

        while (k--)
        {
            int top = pq.top();
            cout << top << " ";
            pq.pop();

            pq.push((int)sqrt(top));
        }

        while (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }

        return ans;
        cout << endl;
    }
};
