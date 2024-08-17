// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
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

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        if (n > 2)
            cout << "NO" << endl;
        else
        {
            if (abs(nums[0] - nums[1]) > 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}