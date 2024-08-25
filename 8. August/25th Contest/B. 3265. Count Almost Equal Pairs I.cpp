// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

string swap(string second, int i)
{
    char temp = second[i];
    second[i] = second[i + 1];
    second[i + 1] = temp;

    return second;
}

int compare(string first, string second)
{
    if (first == second)
        return 1;

    int n = first.size();
    int m = second.size();

    if (abs(n - m) > 1)
        return 0;

    if (n == 1 && m == 1)
    {
        return first == second;
    }

    int a = stoi(first);
    int limit = m; // for purpose of loop condition
    string swapper = second;

    if (n > m)
    {
        a = stoi(second);
        swapper = first;
        limit = n;
    }

    for (int i = 0; i < limit - 1; i++)
    {
        // keep swapping and compare to the number

        string copy = swap(swapper, i);
        int b = stoi(copy);

        if (a == b)
            return 1;
    }

    return 0;
}

int countPairs(vector<int> &nums)
{

    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            string first = to_string(nums[i]);
            string second = to_string(nums[j]);

            // now do the comparison between both
            count += compare(first, second);
        }
    }

    return count;
}
int main()
{
    vi nums{8, 12, 5, 5, 14, 3, 12, 3, 3, 6, 8, 20, 14, 3, 8};
    cout << countPairs(nums) << endl;
}