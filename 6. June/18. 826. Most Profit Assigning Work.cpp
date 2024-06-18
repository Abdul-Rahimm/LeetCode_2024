// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
{
    vector<vector<int>> pairs;
    int total = 0;

    for (int i = 0; i < profit.size(); i++)
    {
        pairs.push_back({difficulty[i], profit[i]});
    }

    sort(pairs.begin(), pairs.end());
    sort(worker.begin(), worker.end());

    int n = worker.size();
    int maxProfit = 0;

    for (int i = 0, saveidx = 0; i < n; i++)
    {

        int work = worker[i];

        while (saveidx < profit.size() && work >= pairs[saveidx][0])
        {
            saveidx++;
            maxProfit = max(pairs[saveidx - 1][1], maxProfit);
        }

        if (saveidx != 0)
            total += maxProfit;
    }
    return total;
}

int main()
{
    vi diff{2, 4, 6, 8, 10};
    vi profit{10, 20, 30, 40, 50};
    vi worker{4, 5, 6, 7};

    cout << maxProfitAssignment(diff, profit, worker) << endl;
}