// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool palindrome(string word)
{
    int first = 0, last = word.size() - 1;

    while (first < last)
    {
        if (word[first] != word[last])
            return false;

        first++;
        last--;
    }

    return true;
}

string firstPalindrome(vector<string> &words)
{
    for (string word : words)
    {
        if (palindrome(word))
            return word;
    }

    return "";
}