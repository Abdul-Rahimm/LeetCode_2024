// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool isVowel(char curr)
{
    return curr == 'a' || curr == 'e' || curr == 'i' || curr == 'o' || curr == 'u';
}
void handleVowelAdd(char curr, vector<bool> &vowels, bool &allVowelStatus)
{
    if (curr == 'a')
    {
        vowels[0] = true;
    }
    else if (curr == 'e')
    {
        vowels[1] = true;
    }
    else if (curr == 'i')
    {
        vowels[2] = true;
    }
    else if (curr == 'o')
    {
        vowels[3] = true;
    }
    else if (curr == 'u')
    {
        vowels[4] = true;
    }

    for (int i = 0; i < 5; i++)
    {
        if (vowels[i] == false)
            return;
    }

    allVowelStatus = true;
}
void handleVowelRemove(char curr, vector<bool> &vowels, bool &allVowelStatus)
{
    if (curr == 'a')
    {
        vowels[0] = false;
    }
    else if (curr == 'e')
    {
        vowels[1] = false;
    }
    else if (curr == 'i')
    {
        vowels[2] = false;
    }
    else if (curr == 'o')
    {
        vowels[3] = false;
    }
    else if (curr == 'u')
    {
        vowels[4] = false;
    }

    allVowelStatus = false;
}

int countOfSubstrings(string word, int k)
{
    int ans = 0;
    int cons = 0;
    vector<bool> vowels(5, false);
    bool allVowelStatus = false;
    int n = word.size();
    int i = 0;
    int j = 0;

    while (j < n)
    {
        char curr = word[j];

        if (isVowel(curr))
        {
            handleVowelAdd(curr, vowels, allVowelStatus);
        }
        else
        {
            cons++;
        }

        if (allVowelStatus && cons == k)
            ans++;

        while (cons > k)
        {
            if (isVowel(word[i]))
                handleVowelRemove(word[i], vowels, allVowelStatus);
            else
                cons--;
            i++;
        }

        j++;
    }

    return ans;
}

int main()
{
    string word = "ieaouqqieaouqq";
    int k = 1;

    cout << countOfSubstrings(word, k) << endl;
}