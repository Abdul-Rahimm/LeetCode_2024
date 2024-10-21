// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int main()
{
    int n;
    cin >> n;

    unordered_set<int> st;
    int num;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        st.insert(num);
    }

    cout << st.size() << endl;
}