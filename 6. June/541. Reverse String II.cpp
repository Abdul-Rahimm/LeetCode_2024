// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

string reverseStr(string s, int k)
{
    int n = s.size();

    int iterations = ceil((float)n / (2 * k));

    for (int i = 0; i < iterations; i++)
    {
        int skip = i * 2 * k;
        reverse(s.begin() + skip, s.begin() + skip + k);
    }

    return s;
}

int main()
{
    string s = "abcdefg";
    cout << reverseStr(s, 2) << endl;
}