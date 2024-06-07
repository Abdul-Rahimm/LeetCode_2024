// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
string matchWord(string word, vector<string> dict)
{
    for (int i = 0; i < dict.size(); i++)
    {
        string curr = dict[i];

        for (int j = 0; j < curr.size(); j++)
        {
            if (word[j] != curr[j])
                break;

            if (j == curr.size() - 1)
                return curr;
        }
    }

    return word;
}

string replaceWords(vector<string> &dictionary, string sentence)
{
    int n = dictionary.size();
    stringstream obj(sentence); // pass the string to obj
    string answer = "";

    // To store individual words
    string word;

    int count = 0;
    while (obj >> word)
    {
        // each individual word is coming to us

        string match = matchWord(word, dictionary);
        for (char i : match)
            answer += i;

        answer += " ";
    }
    answer.pop_back(); // to remove the last space

    return answer;
}

int main()
{
    vector<string> dict{"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    string answer = replaceWords(dict, sentence);
    cout << answer << endl;
}