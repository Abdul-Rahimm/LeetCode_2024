// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void print(unordered_set<int> st)
{
    for (auto i : st)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    unordered_set<int> st;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }

    print(st);
}