// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int n, m;
int solve(vector<string> &words, string target, int charIndex)
{
    if (charIndex == target.size())
    {
        return 1;
    }
    if (charIndex >= m)
        return 0;

    int answer = 0;

    for (int j = charIndex; j < m; j++)
        for (int i = 0; i < n; i++)
        {
            if (target[charIndex] == words[i][j])
            {
                answer += solve(words, target, charIndex + 1);
            }
        }

    return answer;
}
int numWays(vector<string> &words, string target)
{
    n = words.size();
    m = words[0].size();

    return solve(words, target, 0);
}

int main()
{
    vector<string> words{"acca", "bbbb", "caca"};
    string target = "aba";

    int ans = numWays(words, target);
    cout << ans << endl;
}