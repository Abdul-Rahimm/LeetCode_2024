// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> findAllPeople(int n, vector<vector<int>> &nums, int firstPerson)
{
    auto comparater = [](vector<int> &row1, vector<int> &row2) -> bool
    {
        return row1[2] < row2[2];
    };
    sort(nums.begin(), nums.end(), comparater);

    int n = nums.size();
    vector<int> ans;
    set<int> st;

    st.insert(0);
    st.insert(firstPerson);

    for (int i = 0; i < n; i++)
    {
        vector<int> row = nums[i];

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
int main()
{
    vector<vector<int>> nums{{1, 2, 5}, {2, 3, 4}, {1, 5, 7}};

    print(nums);
}