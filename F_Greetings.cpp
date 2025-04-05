// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int recur(int i, int cap, vector<int> &value, vector<int> &weight)
{
    if (i >= value.size() || weight[i] > cap)
        return 0;

    int take = value[i] + recur(i + 1, cap - weight[i], value, weight);
    int nott = recur(i + 1, cap, value, weight);

    return max(take, nott);
}

int main()
{
    int capacity = 10;
    vector<int> value{10, 20, 30};
    vector<int> weight{2, 4, 6};

    cout << recur(0, 10, value, weight);
}