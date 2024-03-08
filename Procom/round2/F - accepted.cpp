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
#define FILE_READ_IN freopen("mixmilk.in", "r", stdin);
#define FILE_READ_OUT freopen("mixmilk.out", "w", stdout);
#define all(a) a.begin(), a.end()
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
bool status = false;

void solve()
{
    FILE_READ_IN;
    FILE_READ_OUT;
    int c1, m1, c2, m2, c3, m3;
    cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;

    unordered_set<string> st;

    for (int i = 1; i < INT_MAX; i++)
    {

        string key = to_string(m1) + " " + to_string(m2) + " " + to_string(m3);

        // for(int i = 0 ; i < INT_MAX/2 ; i++){

        // }

        // string found. repating state found
        if (st.find(key) != st.end())
            status = true;

        if (i % 3 == 1)
        {
            // pour a into b
            if (c2 >= m2 + m1)
            {
                // means capacity is greater so put all milk
                m2 = m2 + m1;
                m1 = 0;
            }
            else
            {
                int pour = c2 - m2; // this much u can pour
                m2 += pour;
                m1 -= pour;
            }

            if (status)
            {
                cout << m1 << endl
                     << m2 << endl
                     << m3;
                return;
            }
        }
        else if (i % 3 == 2)
        {
            // pour b into c
            if (c3 >= m3 + m2)
            {
                // means capacity is greater so put all milk
                m3 = m3 + m2;
                m2 = 0;
            }
            else
            {
                int pour = c3 - m3; // this much u can pour
                m3 += pour;
                m2 -= pour;
            }
        }
        else
        {
            // pour c into a
            if (c1 >= m3 + m1)
            {
                // means capacity is greater so put all milk
                m1 = m3 + m1;
                m3 = 0;
            }
            else
            {
                int pour = c1 - m1; // this much u can pour
                m1 += pour;
                m3 -= pour;
            }
        }
        string keyInsert = to_string(m1) + " " + to_string(m2) + " " + to_string(m3);
        st.insert(keyInsert);
    }
}

int main()
{
    int t = 1;
    //    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}