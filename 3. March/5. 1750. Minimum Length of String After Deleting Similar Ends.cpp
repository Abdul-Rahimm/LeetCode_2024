class Solution
{
public:
    int minimumLength(string s)
    {
        int n = s.length();

        int i = 0, j = n - 1;

        while (i < j)
        {

            char first = s[i];

            while (s[i] == s[j] && i < n)
                i++;
            while (s[j] == first && j > 0 && j > i)
                j--;

            if (s[i] != s[j])
                break;
        }

        // return j-i+1;
        return max(j - i + 1, 0);
    }
};