// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int maxProfit(vector<int> &prices)
{
    int buyPrice = prices[0];
    int profit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] < buyprice)
        {
            buyPrice = prices[i];
        }

        int currentProfit = prices[i] - buyPrice;
        profit = max(profit, currentProfit);
    }

    return profit;
}