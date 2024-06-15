// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
// time complexity  - how much time your code takes to run/compile
// space complexity - map space

vector<int> findWordsContaining(vector<string> &words, char x)
{

    // Design
    //  1. iterate over all strings in the array
    //  2. for each string --> if the char exists or not
    //      3. if char exists --> uss string ka index ko push krdenge vector<int> indexes
    //  4. return vector<int>

    vector<int> indexes;

    for (int i = 0; i < words.size(); i++)
    {

        string current = words[i]; //"leet"

        for (char ch : current)
        {

            // char by char iterate over leet
            if (ch == x)
            {
                // char found in current word -- error
                indexes.push_back(i);
                break; // inner for loop se bahar
            }
        }
    }

    return indexes;
}

void print(vector<int> nums)
{
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<string> words{"leet", "codee"};
    vector<int> answer = findWordsContaining(words, 'e');
    print(answer);
}