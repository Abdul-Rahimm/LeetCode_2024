// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vi nums(n);
        vi prefixSum(n + 1, 0);
        int total = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            total += nums[i];

            prefixSum[i + 1] = total;
        }

        string s;
        cin >> s;

        int right = 0, left = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L')
                left++;
            else
                right++;
        }

        int minSize = min(left, right);

        vector<int> l(minSize);
        vector<int> r(minSize);

        int count = 0;
        int i = 0, j = s.size() - 1;

        while (count < minSize)
        {
            while (s[i] != 'L')
                i++;

            l[count] = i;
            i++;

            while (s[j] != 'R')
                j--;

            r[count] = j;
            j--;

            count++;
        }

        cout << "left " << endl;
        print(l);
        cout << "right " << endl;
        print(r);
    }
}