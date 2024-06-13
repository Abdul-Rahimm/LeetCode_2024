// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minMovesToSeat(vector<int> &seats, vector<int> &students)
{
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());

    int result = 0;
    for (int i = 0; i < seats.size(); i++)
    {
        result += abs(seats[i] - students[i]);
    }

    return result;
}