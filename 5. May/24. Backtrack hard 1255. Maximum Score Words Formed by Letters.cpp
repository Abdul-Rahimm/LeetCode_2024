// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void print(unordered_map<char, int> mp)
{
    for (auto pair : mp)
    {
        cout << pair.first << " : " << pair.second << endl;
    }
}

bool fulfills(string word, unordered_map<char, int> freq)
{
    for (char i : word)
    {
        if (freq[i] <= 0)
        {
            return false;
        }

        freq[i]--;
    }

    return true;
}
int takeWord(string word, unordered_map<char, int> &freq, unordered_map<char, int> &scores)
{
    int result = 0;

    for (char i : word)
    {
        result += scores[i];
        freq[i]--;
    }

    return result;
}

int solve(int i, unordered_map<char, int> &scores, unordered_map<char, int> &freq, vector<string> &words)
{
    if (i >= words.size())
        return 0;

    // take case
    int take = 0;
    string word = words[i];

    bool status = fulfills(word, freq); // if word can be constructed this returns true

    unordered_map<char, int> freq_copy = freq;

    if (status)
    {
        int value = takeWord(word, freq_copy, scores); // explore
        take = value + solve(i + 1, scores, freq_copy, words);
    }

    // not take case
    int not_take = solve(i + 1, scores, freq, words);

    return max(take, not_take);
}

int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
{
    unordered_map<char, int> scores;
    unordered_map<char, int> freq;

    for (int i = 0; i < 26; i++)
        scores[char(i + 97)] = score[i];

    for (char i : letters)
        freq[i]++;

    return solve(0, scores, freq, words);
}

int main()
{
    vector<string> words{"xxxz", "ax", "bx", "cx"};
    vector<char> letters{'z', 'a', 'b', 'c', 'x', 'x', 'x'};
    vector<int> score{4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10};

    int answer = maxScoreWords(words, letters, score);
    cout << answer << endl;
}