// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

static bool myFunction(int a, int b)
{
    string s1 = to_string(a);
    string s2 = to_string(b);

    return (s1 + s2) > (s2 + s1);
}
string largestNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), myFunction);

    if (nums[0] == 0)
        return "0";
    string result = "";
    for (int i : nums)
        result += to_string(i);
    return result;
}