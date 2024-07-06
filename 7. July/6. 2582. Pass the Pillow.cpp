// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int passThePillow(int n, int time)
{
    int turns = n - 1;

    time = time % (turns * 2);

    if (time > n - 1)
    {
        int number = time % n;
        return n - number - 1;
    }
    else
    {
        return time + 1;
    }

    return 0;
}