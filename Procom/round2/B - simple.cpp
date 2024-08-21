// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
// sliding window
// nested loops
int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    vector<int> answer;  //{7, 8, 9, 10}
    int n = nums.size(); // 6

    int window = 5;
    int sum = 0;

    // window sliding approach
    for (int i = 0; i < window; i++)
    {
        sum += nums[i];
    }

    answer.push_back(sum);

    // i place the ptrs here initially
    int i = 1;
    int j = window;

    while (j < n)
    {

        sum -= nums[i - 1];
        sum += nums[j];

        answer.push_back(sum);

        i += 1;
        j += 1;
    }

    print(answer);
}
// Time complexity - 24 operations