// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int main()
{
    deque<string> deq1;

    deq1.push_back("Hello");
    deq1.push_back("World");
    deq1.push_front("Hi");

    cout << deq1.front() << endl;
}