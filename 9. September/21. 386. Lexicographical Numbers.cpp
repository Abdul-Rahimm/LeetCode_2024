// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int n;
void solve(vector<int> &ans, int num)
{
    if (num > n)
        return;

    for (int i = 0; i <= 9; i++)
    {
        string newNumber = to_string(num) + to_string(i);
        int number = stoi(newNumber);

        if (number <= n)
            ans.push_back(number);

        solve(ans, number);
    }
}
vector<int> lexicalOrder(int limit)
{
    vector<int> ans;
    n = limit;

    for (int i = 1; i <= 9; i++)
    {
        if (i <= n)
            ans.push_back(i);

        solve(ans, i);
    }

    return ans;
}

int main()
{

    int num = 13;
    vector<int> ans = lexicalOrder(num);
    print(ans);
}