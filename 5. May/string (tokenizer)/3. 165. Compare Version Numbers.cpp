// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<string> getTokens(string s)
{
    stringstream ss(s); // string converted into stream

    string token = "";
    vector<string> tokens;

    while (getline(ss, token, '.'))
    {
        tokens.push_back(token);
    }

    return tokens;
}

int compareVersion(string version1, string version2)
{

    vector<string> v1 = getTokens(version1);
    vector<string> v2 = getTokens(version2);

    int m = v1.size();
    int n = v2.size();
    int i = 0;

    while (i < m || i < n)
    {

        int a = i < m ? stoi(v1[i]) : 0;
        int b = i < n ? stoi(v2[i]) : 0;

        if (a < b)
            return -1;
        if (a > b)
            return 1;
        else
            i++;
    }

    return 0;
}