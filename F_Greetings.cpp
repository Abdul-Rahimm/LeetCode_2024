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
    string name = "abdul raheem";
    string *ptr = &name; // pointer creation

    cout << *ptr; // dereference
}