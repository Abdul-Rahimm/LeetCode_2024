// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef array<int, 2> ii;
typedef vector<ii> vii;
const int mod = 1e9 + 7;

void solve();
signed main(void)
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;

    while (tc--)
        solve();

    return 0;
}

void solve1(vector<vector<int>> &safe, int n, int row, int c)
{
    for (int i = 0; i < n; i++)
    {
        safe[row][i]++;
    }
    for (int i = row + 1; i < n; i++)
    {
        safe[i][c]++;
        if (c + i - row < n)
            safe[i][c + i - row]++;
        if (c - i + row >= 0)
            safe[i][c - i + row]++;
    }
}
// This function is used to backtrack
void solve2(vector<vector<int>> &safe, int n, int row, int c)
{
    for (int i = 0; i < n; i++)
    {
        safe[row][i]--;
    }
    for (int i = row + 1; i < n; i++)
    {
        safe[i][c]--;
        if (c + i - row < n)
            safe[i][c + i - row]--;
        if (c - i + row >= 0)
            safe[i][c - i + row]--;
    }
}
void solve(int n, vector<vector<string>> &ans, vector<vector<int>> &safe, int row, vector<string> &tempo)
{
    if (row == n)
    {
        ans.push_back(tempo);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (safe[row][i] == 0)
        {
            solve1(safe, n, row, i);
            tempo[row][i] = 'Q';
            solve(n, ans, safe, row + 1, tempo);
            tempo[row][i] = '.';
            solve2(safe, n, row, i);
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<int>> safe;
    vector<vector<string>> ans;
    vector<string> tempo;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        string a;
        for (int j = 0; j < n; j++)
        {
            a = a + ".";
            temp.push_back(0);
        }
        tempo.push_back(a);
        safe.push_back(temp);
    }
    int row = 0;
    solve(n, ans, safe, row, tempo);
    return ans;
}

void print(vector<vector<string>> &ans)
{
    int count = 0;
    for (vector<string> row : ans)
    {
        cout << "Option " << ++count << " to place all the queens: " << endl;
        for (string i : row)
        {
            for (char ch : i)
            {
                cout << ch << " ";
            }
            cout << endl;
        }

        cout << endl
             << endl;
    }
}

void solve()
{
    cout << "Please Enter the Dimensions of the Grid.\nn = ";
    int n = 4;
    cin >> n;
    cout << endl;

    vector<vector<string>> ans = solveNQueens(n);
    print(ans); // prints the chess board
}