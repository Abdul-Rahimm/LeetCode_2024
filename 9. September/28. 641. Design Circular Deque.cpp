// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class MyCircularDeque
{
public:
    int limit;
    vector<int> nums;
    MyCircularDeque(int k)
    {
        limit = k;
    }

    bool insertFront(int value)
    {
        if (!isFull())
        {
            nums.insert(nums.begin(), value);
            return true;
        }
        return false;
    }

    bool insertLast(int value)
    {
        if (!isFull())
        {
            nums.push_back(value);
            return true;
        }
        return false;
    }

    bool deleteFront()
    {
        if (!isEmpty())
        {
            nums.erase(nums.begin());
            return true;
        }
        return false;
    }

    bool deleteLast()
    {
        if (!isEmpty())
        {
            nums.pop_back();
            return true;
        }
        return false;
    }

    int getFront()
    {
        if (!isEmpty())
        {
            return nums[0];
        }
        return -1;
    }

    int getRear()
    {
        if (!isEmpty())
        {
            return nums[nums.size() - 1];
        }
        return -1;
    }

    bool isEmpty()
    {
        return nums.size() == 0;
    }

    bool isFull()
    {
        return nums.size() == limit;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */