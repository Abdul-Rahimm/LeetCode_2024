// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int countKConstraintSubstrings(string s, int k)
{

    int i = 0, j = 0;
    int n = s.size();
    int count = 0;
    int zeros = 0, ones = 0;

    while (j < n)
    {

        if (s[j] == '0')
            zeros++;
        else
            ones++;

        while (zeros > k && ones > k)
        {
            if (s[i] == '0')
                zeros--;
            else
                ones--;

            i++;
        }

        count += j - i + 1;
        j++;
    }

    return count;
}

int main()
{
}