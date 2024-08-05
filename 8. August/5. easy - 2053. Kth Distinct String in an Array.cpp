// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

string kthDistinct_Failed(vector<string> &arr, int k)
{
    unordered_map<string, int> mp;

    int n = arr.size();

    int kthDistinct = 1;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i]) == mp.end())
        {
            mp[arr[i]] = kthDistinct;
            kthDistinct++;
        }
        else
        {
            mp.erase(arr[i]);
        }
    }

    int mapSize = mp.size();
    for (auto row : mp)
    {
        string current = row.first;
        int second = row.second;

        if (second)
    }

    print(mp);
    return "";
}
string kthDistinct(vector<string> &arr, int k)
{
    unordered_map<string, int> mp;

    for (string s : arr)
        mp[s]++;

    int count = 0;

    for (string s : arr)
    {
        if (mp[s] == 1)
            count++;

        if (count == k)
            return s;
    }

    return "";
}
int main()
{
    vector<string> arr{"y", "napli", "jfqjc", "mbl", "oeush"};
    int k = 3;

    cout << kthDistinct(arr, k) << endl;
}
