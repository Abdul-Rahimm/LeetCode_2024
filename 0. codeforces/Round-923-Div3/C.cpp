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
int req;

signed main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;

    while (tc--)
        solve();

    return 0;
}
bool solved(int i, int j, vi &first, vi &second, int ascore, int bscore, int need)
{

    if (i >= first.size() || j >= second.size())
        return false;
    if (ascore + bscore == req && ascore == bscore)
        return true;

    bool firstpath = false, secondpath = false, nottake = false;
    if (first[i] == need && second[j] == need)
    {
        firstpath = solved(i + 1, j, first, second, ascore + 1, bscore, need + 1);
        secondpath = solved(i, j + 1, first, second, ascore, bscore + 1, need + 1);
    }
    else if (first[i] == need)
    {
        firstpath = solved(i + 1, j, first, second, ascore + 1, bscore, need + 1);
    }
    else if (second[j] == need)
    {
        secondpath = solved(i, j + 1, first, second, ascore, bscore + 1, need + 1);
    }
    else
        nottake = solved(i + 1, j + 1, first, second, ascore, bscore, need);

    return firstpath | secondpath | nottake;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    req = k;

    vector<int> first(n);
    for (int &i : first)
        cin >> i;

    vector<int> second(m);
    for (int &i : second)
        cin >> i;

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    bool ans = solved(0, 0, first, second, 0, 0, 1);
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}