// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

string stringHash(string s, int k)
{

    int n = s.size();
    int count = n / k;
    string ans;

    for (int j = 0; j < count; j++)
    {
        int count = 0;

        for (int i = 0; i < k; i++)
        {
            char currentChar = s[(j * k) + i];
            int value = int(currentChar) - 'a';
            count = (count + value) % 26;
        }

        char current = 'a' + count;
        ans.push_back(current);
    }

    return ans;
}

int main()
{
    string ans = stringHash("abcd", 2);
}