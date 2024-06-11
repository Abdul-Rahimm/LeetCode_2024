// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
vi nums;
bool comparater(int i, int j)
{
    int index_i = nums[i];
    int index_j = nums[j];

    return index_i > index_j;
}

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    map<int, int> mp;
    vector<int> answer;

    for (int i : arr1)
    {
        mp[i]++;
    }

    for (int i = 0; i < arr2.size(); i++)
    {
        int curr = arr2[i];

        while (mp[curr]--)
        {
            answer.push_back(curr);
        }
        mp.erase(curr);
    }

    for (auto pair : mp)
    {
        int freq = pair.second;
        int num = pair.first;

        while (freq--)
        {
            answer.push_back(num);
        }
    }

    return answer;
}

void print(vi nums)
{
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{

    vi arr1{2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vi arr2{2, 1, 4, 3, 9, 6};

    vi answer = relativeSortArray(arr1, arr2);
    print(answer);
}