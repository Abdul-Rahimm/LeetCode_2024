// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minFlips(int a, int b, int c)
{
    int flips = 0;
    a *= 2, b *= 2, c *= 2;

    while (a != 0 || b != 0 || c != 0)
    {
        // chaipi scene
        a >>= 1;
        b >>= 1;
        c >>= 1;

        // seeing each bit
        int aBit = a & 1;
        int bBit = b & 1;
        int cBit = c & 1;

        int a_or_b = aBit | bBit;

        if (cBit == a_or_b)
            continue;

        if (cBit == 1)
        {
            if (aBit == 0 && bBit == 0)
                flips++;
        }
        else // cbit == 0
        {
            if (aBit == 1)
                flips++;
            if (bBit == 1)
                flips++;
        }
    }
    return flips;
}

int main()
{
    int answer = minFlips(2, 6, 5);
    cout << answer << endl;
}