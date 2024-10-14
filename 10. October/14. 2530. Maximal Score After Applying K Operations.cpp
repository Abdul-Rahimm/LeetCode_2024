// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

long long maxKelements(vector<int> &nums, int k)
{
    priority_queue<int> pq;
    long long ans = 0;
    for (int i : nums)
        pq.push(i);

    for (int i = 0; i < k; i++)
    {
        int current = pq.top();
        pq.pop();

        ans += current;
        pq.push(ceil(current / 3.0));
    }

    return ans;
}

int main()
{
    vi nums{10, 10, 10, 10, 10};
    long long ans = maxKelements(nums, 5);
    cout << ans << endl;
    ans = maxKelements(nums, 6);
    cout << ans << endl;
}