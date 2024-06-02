// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minBitFlips(int start, int goal)
{
    int flips = 0;

    while (start != 0 || goal != 0)
    {
        int startBit = start & 1;
        int goalBit = goal & 1;

        if (startBit != goalBit)
            flips++;

        start >>= 1;
        goal >>= 1;
    }

    return flips;
}

int main()
{

    cout << minBitFlips(10, 7) << endl;
}