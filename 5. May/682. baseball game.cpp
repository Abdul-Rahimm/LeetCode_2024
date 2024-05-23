class Solution
{
public:
    bool isOperation(char curr)
    {
        return curr == '+' || curr == 'D' || curr == 'C';
    }

    int calPoints(vector<string> &operations)
    {
        int n = operations.size();
        vector<int> nums;

        for (int i = 0; i < n; i++)
        {
            char current = operations[i][0];

            if (!isOperation(current))
            {
                // convert to number
                int size_num = operations[i].size();
                int num = 0;
                bool negative = false;

                if (operations[i][0] == '-')
                    negative = true;

                int j = negative == true ? 1 : 0;

                for (; j < size_num; j++)
                {
                    int number = int(operations[i][j]) - 48;
                    num = (num * 10) + number;
                }

                if (negative)
                    num *= -1;

                nums.push_back(num);
            }
            else if (current == 'C')
                nums.pop_back();
            else if (current == 'D')
                nums.push_back(nums.back() * 2);
            else
            {
                int size = nums.size() - 1;
                nums.push_back(nums[size] + nums[size - 1]);
            }
        }

        return accumulate(nums.begin(), nums.end(), 0);
    }
};