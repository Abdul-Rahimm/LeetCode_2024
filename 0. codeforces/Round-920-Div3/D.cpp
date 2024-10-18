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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;

    while (tc--)
        solve();

    return 0;
}

void solve()
{

    long long a, b;
    cin >> a >> b;
    vector<long long> nums1(a);
    for (long long &i : nums1)
        cin >> i;

    vector<long long> nums2(b);
    for (long long &i : nums2)
        cin >> i;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end(), greater<long long>());

    long long i = 0;
    long long j1 = nums1.size() - 1;
    long long j2 = nums2.size() - 1;

    long long ans = 0;
    long long count = (j1 + 1 - i) / 2;

    while (a--)
    {
        int first = abs(nums1[j1] - nums2[j2]);
        int second = abs(nums1[i] - nums2[i]);

        if (first > second)
        {
            ans += first;
            j1--;
            j2--;
        }
        else
        {
            ans += second;
            i++;
        }
    }

    cout
        << ans << endl;
}