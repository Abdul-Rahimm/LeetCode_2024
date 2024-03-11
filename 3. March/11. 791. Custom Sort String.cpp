class Solution
{
public:
    string customSortString(string order, string s)
    {
        vector<int> mp(26, -1);

        int count = 0;
        for (char i : order)
        {
            mp[i - 'a'] = count;
            count++;
        }

        auto myComparater = [&mp](char &c1, char &c2)
        {
            return mp[c1 - 'a'] < mp[c2 - 'a'];
        };

        sort(s.begin(), s.end(), myComparater);

        return s;
    }
};