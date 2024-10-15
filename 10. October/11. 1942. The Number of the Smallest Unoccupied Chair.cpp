// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int smallestChair(vector<vector<int>> &times, int targetFriend)
{
    map<int, int> mp;
    int i = 0;
    for (auto row : times)
    {
        mp[row[0]] = row[1];
    }

    print(mp);

    return 0;
}

int main()
{
    vii nums{{33889, 98676}, {80071, 89737}, {44118, 52565}, {52992, 84310}, {78492, 88209}, {21695, 67063}, {84622, 95452}, {98048, 98856}, {98411, 99433}, {55333, 56548}, {65375, 88566}, {55011, 62821}, {48548, 48656}, {87396, 94825}, {55273, 81868}, {75629, 91467}};
    int target = 0;

    cout << smallestChair(nums, target) << endl;
}