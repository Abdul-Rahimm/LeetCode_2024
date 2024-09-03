// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void populate(vi &nums, int num)
{
    if (num < 10)
        for (int i = 0; i < 3; i++)
            nums[i] = 0;

    if (num < 100)
        for (int i = 0; i < 2; i++)
            nums[i] = 0;

    if (num < 1000)
        nums[0] = 0;

    int index = nums.size() - 1;
    while (num > 0)
    {
        nums[index] = num % 10;
        num /= 10;
        index--;
    }
}

int generateKey(int num1, int num2, int num3)
{

    vi nums1(4), nums2(4), nums3(4);

    populate(nums1, num1);
    populate(nums2, num2);
    populate(nums3, num3);

    int number = 0;
    int mul = 1;
    int answer = 0;

    for (int i = 0; i < 4; i++)
    {

        answer *= 10;
        int current = min({nums1[i], nums2[i], nums3[i]});
        answer += current;
    }

    return answer;
}