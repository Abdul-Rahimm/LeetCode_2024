#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

long long xlargestPerimeter(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    long long sum = 0;
    deque<int> q;
    int total = 0;
    int maxTotal = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        if (q.size() < 3)
        {
            q.push_back(nums[i]);
            total += nums[i];
        }
        else
        {
            if (nums[i] < total)
            {
                q.push_back(nums[i]);
                total += nums[i];
            }
            else
            {
                total -= q.front();
                q.pop_back();
            }
        }

        maxTotal = max(total, maxTotal);
    }

    return q.size() >= 3 ? maxTotal : -1;
}

long long largestPerimeter(vector<int> &nums)
{
    int i = 0;
    int j = 0;
    int total = 0;
    int largest = 0;

    for (int num : nums)
    {

        if (i < 2)
        {
            total += num;
            i++;
            j++;
        }

        // longest side smaller the sum of other sides
        if (total < num)
            i = j;

        total += num;
        j++;
    }

    total = 0;
    for (int j = 0; j < i; j++)
        total += nums[j];

    return i > 2 ? total : -1;
}

int main()
{
    fastio;
    vector<int> nums{1, 12, 1, 2, 5, 50, 3};
    cout << largestPerimeter(nums) << endl;
    return 0;
}