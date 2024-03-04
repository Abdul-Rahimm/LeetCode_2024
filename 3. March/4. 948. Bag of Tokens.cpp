class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());

        int first = 0, last = tokens.size() - 1;
        int max_score = 0;
        int score = 0;

        while (first <= last)
        {
            bool status = false;

            if (tokens[first] <= power)
            {
                power -= tokens[first];
                score++;
                first++;
                status = true;
            }
            else if (score >= 1)
            {
                power += tokens[last];
                score--;
                last--;
                status = true;
            }

            if (!status)
                break;

            max_score = max(max_score, score);
        }

        return max_score;
    }
};