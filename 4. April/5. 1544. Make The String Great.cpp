// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

string makeGood(string s)
{
    string result = "";

    for (char &ch : s)
    {
        if (result.size() > 0 && (ch + 32 == result.back() || ch - 32 == result.back()))
        {
            result.pop_back();
        }
        else
        {
            result.push_back(ch);
        }
    }

    return result;
}

int main()
{
    makeGood("aA");
}