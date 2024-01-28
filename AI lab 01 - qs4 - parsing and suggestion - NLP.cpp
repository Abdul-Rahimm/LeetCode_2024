// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

unordered_map<string, vector<string>> mp; // to store which word comes after which word.
unordered_set<string> st;                 // created to solve the repitition of suggestions

void convertToLower(string &sen)
{
    // function to convert a word to lowercase

    for (int i = 0; i < sen.size(); i++)
    {
        sen[i] = tolower(sen[i]);
    }
}

void suggestion(string s)
{
    stringstream obj(s);
    string intermediate;
    vector<string> tokens;

    // Tokenizing w.r.t. space ' '
    while (getline(obj, intermediate, ' '))
    {
        // use a loop to convert to lower case for standard comparison
        convertToLower(intermediate);

        tokens.push_back(intermediate);
    }

    // inserting the key value pairs as
    // key   --> set of words just after key
    // for example:
    // if the sentence contains "I study CS and I study Bio"

    // I     --> study , study (will have to make sure suggestion doesnt repeat using set Data structure)
    // study --> CS , Bio
    // CS    --> and

    for (int i = 0; i < tokens.size() - 1; i++)
    {
        mp[tokens[i]].push_back(tokens[i + 1]);
    }

    for (auto pair : mp)
    {
        string key = pair.first;
        vector<string> values = pair.second;

        cout << key << " : ";
        for (int i = 0; i < values.size(); i++)
        {
            cout << values[i];

            if (i != values.size() - 1)
                cout << " , ";
        }

        cout << endl;
    }
}

int main()
{
    // for simplicity punctuation marks are not in the string
    string s = "My name is Rahim and I study Computer Science and I study competitive programming";

    suggestion(s);

    vector<string> userSentence;

    for (int i = 0; i < 10000; i++)
    {
        string word;
        cin >> word;

        if (word == "end")
            break;

        userSentence.push_back(word);

        cout << "Sentence: ";
        for (const auto &w : userSentence)
        {
            cout << w << " ";
        }
        cout << endl;

        if (mp.find(word) != mp.end())
        {
            // means that this word was present in sentence one

            cout << "suggestions : ";

            vector<string> values = mp[word];
            for (string i : values)
            {
                // suggestions shouldnt repeat - therefore using set
                if (st.find(i) == st.end())
                    cout << i << " ";

                st.insert(i);
            }
            cout << endl
                 << endl;
        }
    }
}