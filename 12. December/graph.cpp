// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int main()
{
    map<int, vector<int>> mp;
    // dijkstra algorithm

    mp[1].push_back(5);
    mp[5].push_back(1);

    mp[1].push_back(4);
    mp[4].push_back(1);

    mp[1].push_back(2);
    mp[2].push_back(3);
    mp[3].push_back(4);
    mp[5].push_back(4);

    for (auto row : mp)
    {
        int number = row.first; // key
        vector<int> arr = row.second;

        cout << number << " ";
        for (int i : arr)
            cout << i << " ";

        cout << endl;
    }
}