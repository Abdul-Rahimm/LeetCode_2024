class Solution
{
public:
    int maximumLength(string s)
    {
        int n = s.size();
        int ans = -1;
        unordered_map<string, int> mp;

        for (int i = 0; i < n;)
        {
            char curr = s[i];

            string temp;
            while (i < n && (s[i] == curr || temp.empty()))
            {
                temp.push_back(curr);

                mp[temp]++;
                if (temp.size() >= 2)
                {
                    for (int i = 1; i < temp.size(); i++)
                    {
                        mp[temp.substr(i)]++;
                    }
                }
                i++;
            }
            temp.clear();
        }

        for (auto row : mp)
        {
            cout << row.first << " " << row.second << endl;
            // 2 cases
            // 1. len of substring > 3
            // 2. occcurences >= 3
            if (row.second >= 3)
            {
                ans = max(ans, (int)row.first.size());
            }

            if (row.first.size() >= 3)
            {
                ans = max(ans, (int)row.first.size() - 2);
            }
        }

        return ans;
    }
};