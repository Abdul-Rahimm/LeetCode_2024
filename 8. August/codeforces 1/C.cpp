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
        int a;
        cin >> a;

        vector<int> nums(a);
        for (int i = 0; i < a; i++)
        {
            cin >> nums[i];
        }

        int m;
        cin >> m;

        for (int i = 0; i < m; i++)
        {

            string s;
            cin >> s;
            bool status = false;

            if (s.length() != nums.size())
                status = true;

            unordered_map<char, int> mp;

            for (int i = 0; i < s.size(); i++)
            {
                // char by char

                char curr = s[i];

                if (mp.find(curr) == mp.end())
                {
                    mp[curr] = nums[i];
                }
                else
                {
                    // found in map
                    if (mp[curr] != nums[i])
                    {
                        // cout << "NO" << endl;
                        status = true;
                        break;
                    }
                }
            }

            if (!status)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}