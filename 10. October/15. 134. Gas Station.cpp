// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    int gasSum = 0, costSum = 0;
    long long sum = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        gasSum += gas[i];
        costSum += cost[i];

        sum += gas[i] - cost[i];

        if (sum < 0)
        {
            start = i + 1;
            sum = 0;
        }
    }

    if (gasSum - costSum < 0)
        return -1;

    return start;
}

int main()
{
    vi gas{1, 2, 3, 4, 5};
    vi cost{3, 4, 5, 1, 2};

    int ans = canCompleteCircuit(gas, cost);
}