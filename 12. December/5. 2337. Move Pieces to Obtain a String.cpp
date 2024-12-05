class Solution
{
public:
    bool canChange(string start, string target)
    {
        int i = 0;
        int j = 0;
        int n = start.size();
        int lefts = 0, rights = 0;

        bool left = false;
        bool right = false;

        vector<pair<char, int>> chars; // char and index
        for (int i = 0; i < n; i++)
        {
            if (target[i] != '_')
                chars.push_back({target[i], i});

            if (target[i] == 'L')
                lefts++;
            else if (target[i] == 'R')
                rights++;

            if (start[i] == 'L')
                lefts--;
            else if (start[i] == 'R')
                rights--;
        }

        if (lefts != 0 || rights != 0)
            return false;

        while (i < n)
        {
            if (start[i] == '_')
            {
                i++;
                continue;
            }

            if (start[i] == 'L')
            {
                if (chars[j].first != 'L' || chars[j].second > i || j >= chars.size())
                    return false;

                j++;
            }
            else if (start[i] == 'R')
            {
                if (chars[j].first != 'R' || chars[j].second < i || j >= chars.size())
                    return false;

                j++;
            }

            i++;
        }

        return j == chars.size();
    }
};