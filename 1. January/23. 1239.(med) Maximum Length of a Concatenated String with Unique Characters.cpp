// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int n;

int solve(int i, vector<string> &arr, vector<bool> &included, string &path)
{

    if (i >= n)
        return path.size();

    vector<bool> copyIncluded = included; // since original needs to be passed when not taking
    bool status = true;

    string currentString = arr[i];
    for (int index = 0; index < arr[i].size(); index++)
    {
        char ch = currentString[index];
        // means that char is already present in path
        if (included[ch - 'a'] == true)
        {
            status = false;
            break;
        }
        // if not already present then include it
        included[ch - 'a'] = true;
    }

    int take = 0;
    string add = path + arr[i]; // include the current arr[i]

    if (status)
        take = solve(i + 1, arr, included, add);

    int ntake = solve(i + 1, arr, copyIncluded, path);

    return max(take, ntake);
}

int maxLength(vector<string> &arr)
{

    n = arr.size();
    vector<bool> included(26, false); // to see which char is present
    string empty = "";                // initial empty string

    return solve(0, arr, included, empty);
}

int main()
{
    vector<string> array{"un", "iq", "ue"};
    cout << maxLength(array) << endl;
}