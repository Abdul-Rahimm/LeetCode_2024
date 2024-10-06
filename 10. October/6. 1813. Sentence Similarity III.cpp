// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

unordered_map<string, int> mp;

vector<string> tokenize(string str, char delim)
{
    vector<string> tokens;
    string temp = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == delim)
        {
            tokens.push_back(temp);
            temp = "";
        }
        else
            temp += str[i];
    }

    tokens.push_back(temp);
    return tokens;
}

bool areSentencesSimilar(string s1, string s2)
{
    vector<string> s1Tokens = tokenize(s1, ' ');
    vector<string> s2Tokens = tokenize(s2, ' ');

    for (string i : s1Tokens)
        mp[i]++;

    for (string i : s2Tokens)
    {
        if (mp.find(i) != mp.end())
        {
            mp[i]--;

            if (mp[i] == 0)
                mp.erase(i);
        }
    }

    return mp.size() == 0;
}

int main()
{

    string s1 = "My name is Haley";
    string s2 = "My Haley";
    bool ans = areSentencesSimilar(s1, s2);
    cout << ans << endl;
}