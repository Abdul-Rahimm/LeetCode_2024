// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class answer
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size() - 1;
        long long ans = 0;

        while (i < j)
        {
            long long temp = nums[i] + nums[j];

            if (temp > upper)
            {
                j--;
                continue;
            }
            else if (temp < lower)
            {
                i++;
                continue;
            }
            else
            {
                int save_i = i;
                int cnt = 0;

                while (i < j && nums[i] + nums[j] >= lower &&
                       nums[i] + nums[j] <= upper)
                {
                    i++;
                    cnt++;
                }

                ans += cnt;
                i = save_i;
                j--;
            }
        }

        return ans;
    }
};
int main()
{
    vi nums{0, 0, 0, 0, 0, 0};
    answer obj;
    long long ans = obj.countFairPairs(nums, 0, 0);
}