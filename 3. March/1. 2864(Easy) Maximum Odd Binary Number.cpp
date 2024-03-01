class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        string ans;
        int n = s.length();
        int ones = 0, zeroes = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                ones++;
            else
                zeroes++;
        }

        for (int i = 0; i < ones - 1; i++)
            ans.push_back('1');

        for (int i = zeroes; i > 0; i--)
            ans.push_back('0');

        ans.push_back('1');

        return ans;
    }
};