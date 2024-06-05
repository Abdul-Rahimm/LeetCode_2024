// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void print(vector<string> sen)
{
    for (string i : sen)
    {
        cout << i << endl;
    }
}
void print(vector<int> count)
{
    for (int i = 0; i < count.size(); i++)
    {
        cout << char(i + 'a') << " : " << count[i] << endl;
    }
}
int searchChar(char i, vector<string> words)
{
    int minimum = INT_MAX;
    for (string word : words)
    {
        int freq = 0;

        for (char chr : word)
        {
            if (chr == i)
                freq++;
        }

        minimum = min(freq, minimum);
    }

    return minimum;
}
vector<string> commonChars(vector<string> &words)
{
    vector<int> chars(26, 0);
    vector<string> answer;

    int n = words.size();

    for (string str : words)
    {
        // for each string
        unordered_set<char> st;

        for (char i : str)
        {
            if (st.find(i) == st.end())
            {
                // char is not found in the current word

                st.insert(i);
                chars[i - 'a']++;
            }
        }
    }

    // print(chars);

    // now those chars which have freq == words.size()
    // count their freq and min nikalo

    for (int i = 0; i < 26; i++)
    {
        int freq = 0;
        char chr = char(i + 'a');
        if (chars[i] == n)
        {
            freq = searchChar(chr, words);
        }

        for (int i = 0; i < freq; i++)
        {
            // insert chr into answer freq times
            string sentence = "";
            sentence += chr;
            answer.push_back(sentence);
        }
    }

    return answer;
}

int main()
{
    vector<string> sen{"bella", "label", "roller"};
    vector<string> ans = commonChars(sen);

    print(ans);
}