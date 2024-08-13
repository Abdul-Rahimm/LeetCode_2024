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
        bool status = false;

        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++)
        {

            int num;
            cin >> num;

            num -= 1; // 0 indexing

            if (i > 0)
            {

                if ((num == 0 && nums[1] == 0) || (num == n - 1 && nums[n - 2] == 0))
                {
                    // cout << "NO" << endl;
                    status = true;
                }
                else if (nums[num - 1] == 0 && nums[num + 1] == 0)
                {
                    // cout << "NO" << endl;
                    status = true;
                }
            }
            nums[num] = 1;
        }

        if (!status)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}