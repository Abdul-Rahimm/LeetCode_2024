// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        unordered_map<char, int> freq;
        for (char ch : s)
        {
            freq[ch]++;
        }

        priority_queue<char> maxHeap;
        for (auto &[ch, count] : freq)
        {
            maxHeap.push(ch);
        }

        string result;

        while (!maxHeap.empty())
        {
            char ch = maxHeap.top();
            maxHeap.pop();
            int count = freq[ch];

            int use = min(count, repeatLimit);
            result.append(use, ch);

            freq[ch] -= use;

            if (freq[ch] > 0 && !maxHeap.empty())
            {
                char nextCh = maxHeap.top();
                maxHeap.pop();

                result.push_back(nextCh);
                freq[nextCh]--;

                if (freq[nextCh] > 0)
                {
                    maxHeap.push(nextCh);
                }

                maxHeap.push(ch);
            }
        }

        return result;
    }
};