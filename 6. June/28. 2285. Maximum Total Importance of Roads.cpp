// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
bool compareSecondDescending(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

long long maximumImportance(int n, vector<vector<int>> &roads)
{
    vector<int> mp(n, 0);
    vector<pair<int, int>> pr;

    for (vector<int> road : roads)
    {
        int first = road[0];
        int second = road[1];

        mp[first]++;
        mp[second]++;
    }

    for (int i = 0; i < n; i++)
    {
        pr.push_back({i, mp[i]});
    }

    sort(pr.begin(), pr.end(), compareSecondDescending);

    int count = n;
    for (pair<int, int> row : pr)
    {
        int number = row.first;

        mp[number] = count;
        count--;
    }

    long long sum = 0;
    for (vector<int> road : roads)
    {
        sum += mp[road[0]] + mp[road[1]];
    }

    return sum;
}

int main()
{
    vector<vi> vec{{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
    cout << maximumImportance(5, vec) << endl;
}