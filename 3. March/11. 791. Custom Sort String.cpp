class Solution
{
public:
    unordered_map<char, int> mp;

    bool myComparater(char a, char b)
    {
        if (mp[a] < mp[b])
            return true;

        return false;
    }

    string customSortString(string order, string s)
    {

        int count = 1;
        for (char i : order)
        {
            mp[i] = count;
            count++;
        }

        sort(s.begin(), s.end(), myComparater);

        return s;
    }

    string customSortString__Ibrahim(string order, string s)
    {

        int count = 0;
        for (char i : order)
        {
            mp[i] = count;
            count++;
        }

        int n = s.size();
        string ans = "";
        vector<int> freq(order.size(), 0);

        for (int i = 0; i < n; i++)
        {
            // kia map main present hai ya nai
            if (mp.find(s[i]) != mp.end())
            {
                // milgya wala case
                int index = mp[s[i]];

                freq[index]++;
            }
            else
            {
                ans += s[i];
            }
        }

        for (int i = 0; i < freq.size(); i++)
        {
            char ch = mp
        }

        return ans;
    }
};