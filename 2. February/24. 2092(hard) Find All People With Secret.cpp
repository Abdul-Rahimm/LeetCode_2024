// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> findAllPeople(int numberPeople, vector<vector<int>> &nums, int firstPerson)
{
    auto comparater = [](vector<int> &row1, vector<int> &row2) -> bool
    {
        return row1[2] < row2[2];
    };
    sort(nums.begin(), nums.end(), comparater);

    int n = nums.size();
    bool status;

    vector<int> tempValues;
    vector<int> ans;
    set<int> st;

    st.insert(0);
    st.insert(firstPerson);

    for (int i = 0; i < n; i++)
    {
        vector<int> row = nums[i];
        status = false;

        int j = i + 1;
        while (j < n - 1 && row[2] == nums[j][2])
        {
            // push in tempValues and then clear tempValues
            tempValues.push_back(nums[j][1]);
            tempValues.push_back(nums[j][0]);

            if (st.find(nums[j][1]) != st.end() || st.find(nums[j][0]) != st.end())
            {
                status = true;
            }

            j++;
            i++;
        }

        if (status)
        {
            for (int i : tempValues)
            {
                st.insert(i);
            }
        }

        tempValues.clear();

        if (st.find(row[0]) != st.end() || st.find(row[1]) != st.end())
        {
            // means the person knows the secret

            st.insert(row[1]);
            st.insert(row[0]);
        }
    }

    for (int i : st)
        ans.push_back(i);

    return ans;
}
void print(vector<vector<int>> nums)
{
    for (vector<int> row : nums)
    {
        for (int i : row)
            cout << i << " ";
        cout << endl;
    }
}
void print(vector<int> nums)
{
    for (int i : nums)
        cout << i << " ";
}
int main()
{
    vector<vector<int>> nums{{1, 2, 5}, {2, 3, 4}, {1, 5, 7}};
    vector<int> ans = findAllPeople(6, nums, 1);
    print(ans);
}