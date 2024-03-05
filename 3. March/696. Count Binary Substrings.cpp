class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int n = s.length();
        int ans = 0;

        int i = 0, j = 0;

        while (j < n)
        {
            int ones = 0;
            int zeros = 0;
            bool zero = false;
            bool one = false;

            if (s[i] == '0')
            {
                zero = true; // meaning i was at 0
                while (s[i] == '0')
                {
                    zeros++;
                    i++;
                }
            }
            else
            {
                one = true; // meaining i was at 1
                while (s[i] == '1')
                {
                    ones++;
                    i++;
                }
            }

            j = i;

            if (zero)
                while (s[j] == '1')
                {
                    ones++;
                    j++;
                }
            else
                while (s[j] == '0')
                {
                    zeros++;
                    j++;
                }

            int count = min(ones, zeros);
            ans += count;
        }

        return ans;
    }
};