// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
void print(vector<string> &s)
{
    for (string i : s)
    {
        cout << i << endl;
    }
    cout << endl;
}
int findIndex(string word, string current)
{
    int n = word.size();
    int m = current.size();
    int i = 0;

    for (; i < n && i < m; i++)
    {
        if (word[i] != current[i])
            return i;
    }

    return i;
}

bool isIndex(string word, string current, int index)
{
    int n = word.size();
    int m = current.size();
    int i = 0;

    if (n > m)
        return false;
    if (index < n)
        return false;

    return true;
}

void solve(string curr, vector<string> &ans, string s, vector<string> &dict)
{
    if (s.empty())
    {
        ans.push_back(curr);
        return;
    }

    for (string word : dict)
    {
        char start = word[0];

        if (start == s[0])
        {
            // issa match
            string copy = s;
            int index = findIndex(word, s);
            bool isFullWord = isIndex(word, s, index);

            if (isFullWord)
                copy.erase(0, index);
            else
                continue;

            string pass = curr + word;
            if (!copy.empty())
                pass = pass + " ";

            solve(pass, ans, copy, dict);
        }
    }
}

vector<string> wordBreak(string s, vector<string> &wordDict)
{
    vector<string> ans;
    string current = "";

    solve(current, ans, s, wordDict);

    return ans;
}

int main()
{
    string s = "dcacbcadcad";
    vector<string> wordDict{"cbd", "dca", "bcdc", "dcac", "ad"};

    vector<string> ans = wordBreak(s, wordDict);
    print(ans);
}