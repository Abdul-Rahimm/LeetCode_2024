// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void fillVector(vector<string> &vec, string s)
{

    string word;
    int dotCount = 0;
    for (int i = 0; i < s.length(); i++)
    {

        word.push_back(s[i]);

        if (s[i] == '.' || i == s.size() - 1)
        {
            // cant directly push_back the word. remove leading zeros
            int j = 0;
            while (word[j] == '0' && dotCount >= 1)
                word.erase(0, 1);

            if (s[i] == '.')
                word.pop_back(), dotCount++;

            vec.push_back(word);

            word.clear();
        }
    }
}

int compareVersion(string version1, string version2)
{

    vector<string> s1, s2;

    fillVector(s1, version1);
    fillVector(s2, version2);

    int len = max(s1.size(), s2.size());

    for (int i = 0; i < len; i++)
    {

        if (i >= s1.size() && i < s2.size())
        {
            int number = stoi(s2[i]);
            if (number > 0)
                return -1;
        }

        if (i >= s2.size() && i < s1.size())
        {
            int number = stoi(s1[i]);
            if (number > 0)
                return 1;
        }

        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return -1;
    }
    return 0;
}
