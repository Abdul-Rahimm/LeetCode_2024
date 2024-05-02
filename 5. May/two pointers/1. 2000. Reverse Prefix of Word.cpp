class Solution
{
public:
    string reversePrefix(string word, char ch)
    {

        int index = -1;

        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == ch)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
            return word;

        int i = 0, j = index;

        while (i < j)
        {
            char temp = word[i];
            word[i] = word[j];
            word[j] = temp;

            i++;
            j--;
        }

        return word;
    }
};