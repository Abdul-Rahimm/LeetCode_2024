// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class CustomStack
{
public:
    vector<int> nums;
    int limit;
    CustomStack(int maxSize)
    {
        limit = maxSize;
    }

    void push(int x)
    {
        if (nums.size() < limit)
            nums.push_back(x);
    }

    int pop()
    {
        if (nums.size() == 0)
            return -1;

        int value = nums[nums.size() - 1];
        nums.pop_back();
        return value;
    }

    void increment(int k, int val)
    {
        int count = min(k, int(nums.size()));

        for (int i = 0; i < count; i++)
        {
            nums[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */