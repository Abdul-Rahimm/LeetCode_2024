// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void showFrequency(vector<int> nums)
{
    // processing

    // utne numbers input user se and store them in nums

    // output:
    // 1 : 2
    // 2 : 2
    // 3 : 4

    // map use
    //  key  value
    //  int  int
}

void print(vector<int> nums)
{
    for (int number : nums)
    {
        cout << number << " ";
    }
    cout << endl;
}
int main()
{
    // {1,1,2,2,3,3,3,3};
    // vector<int> nums;
    int elements;

    // user asks k nums main kitne number hone chiaye
    cout << "please enter the number of elements: ";
    cin >> elements;

    vector<int> nums(elements); // size
    // utne numbers vector<int> .push_back

    for (int i = 0; i < elements; i++)
    {
        cin >> nums[i];
    }

    print(nums);
}