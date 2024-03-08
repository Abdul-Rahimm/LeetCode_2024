#include <bits/stdc++.h>
// For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define loop(i, a, b) for (int i = a; i < b; i++)
#define loopr(i, a, b) for (int i = a; i >= b; i--)
#define loops(i, a, b, step) for (int i = a; i < b; i += step)
#define looprs(i, a, b, step) for (int i = a; i >= b; i -= step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie();
#define FILE_READ_IN freopen("input.txt", "r", stdin);
#define FILE_READ_OUT freopen("output.txt", "w", stdout);
#define all(a) a.begin(), a.end()
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
vector<vector<char>> mat;
vector<vector<int>> directions{
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
bool valid(int i)
{
    if (i < 0 || i > 2)
        return false;

    return true;
}
int maxcount = 0;
unordered_set<string> st;

int recur(int i, int j, int count)
{
    // if this function goes upto 3 then means match
    int currentCount = count;
    maxcount = max(maxcount, currentCount);

    if (count == 3)
        return 1;

    // unvalid main yahin se return
    //  if(!valid(i) || !valid(j)){
    //      return 0;
    //  }

    char current = mat[i][j];

    for (vector<int> dir : directions)
    {

        int new_i = i + dir[0];
        int new_j = j + dir[1];
        string key = new_i + " " + new_j;

        if (st.empty())
            st.insert(key);

        int number = 0;
        // now see if theyre valid places and if chars match
        if (valid(new_i) && valid(new_j) && mat[new_i][new_j] == current)
            if (st.empty() || st.find(key) != st.end())
                number = recur(new_i, new_j, count + 1);

        if (count == 0)
            st.clear();
    }

    st.clear();
}

bool DFS(char &ans)
{

    // explore from each point and see who wins
    // start explore one by one by storing initial player

    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {

            ans = mat[i][j];
            // starting explore from each bo
            recur(i, j, 0);
            if (maxcount == 3)
                return true;
        }
    }

    return false;
}
void solve()
{

    for (int i = 0; i < 3; i++)
    {
        vector<char> row;
        for (int j = 0; j < 3; j++)
        {
            char str;
            cin >> str;

            row.push_back(str);
        }
        mat.push_back(row);
    }

    char ans;
    if (DFS(ans))
        cout << ans << endl;
    else
        cout << "DRAW" << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
