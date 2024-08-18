// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> decrypt(vector<int> &code, int k)
{

    int n = code.size();
    vector<int> ans;
    // re append the whole array for circular
    for (int i = 0; i < n; i++)
        code.push_back(code[i]);

    // for pos k. start from start
    // for neg k. start from start of reappended array

    if (k == 0)
    {
        vector<int> nums(n, 0);
        return nums;
    }
    else if (k > 0)
    {
        int sum = 0;
        for (int i = 1; i < 1 + k; i++)
        {
            sum += code[i];
        }

        for (int i = 1; i < n; i++)
        {
            ans.push_back(sum);

            sum -= code[i];
            sum += code[i + k];
        }
        ans.push_back(sum);
    }
    // 0  1 2 3 4 5 06 7 8 9 10 11
    // 10 5 7 7 3 2 10 3 6 9 01 06 |10 5 7 7 3 2 10 3 6 9 1 6
    else
    {
        int sum = 0;
        k = abs(k);

        for (int i = n - k; i < n; i++)
        {
            sum += code[i];
        }

        for (int i = n - k; i < (2 * n) - k; i++)
        {
            ans.push_back(sum);

            sum -= code[i];
            sum += code[i + k];
        }
    }

    return ans;
}