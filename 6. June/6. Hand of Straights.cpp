// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
void print(map<int, int> mp)
{
    for (auto row : mp)
    {
        cout << row.first << " : " << row.second << endl;
    }
}

bool isNStraightHand(vector<int> &hand, int groupSize)
{
    if (hand.size() % groupSize != 0)
        return false;

    map<int, int> mp;

    for (int i : hand)
    {
        mp[i]++;
    }

    while (!mp.empty())
    {
        int curr = mp.begin()->first; // 1

        // consecutive groupSize numbers
        for (int i = 0; i < groupSize; i++)
        {
            if (mp[curr + i] == 0)
                return false;

            mp[curr + i]--;

            if (mp[curr + i] == 0)
                mp.erase(mp[curr + i]);
        }
    }

    return true;
}

int main()
{
    vi hand{1, 2, 3, 6, 2, 3, 4, 7, 8};
    cout << isNStraightHand(hand, 3) << endl;
}