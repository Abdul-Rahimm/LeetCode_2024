// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"

using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int maxSatisfied(vector<int> &cus, vector<int> &grumpy, int minutes)
{
    int n = grumpy.size();
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        if (grumpy[i] == 0)
            total += cus[i];
    }

    int grumpPoints = 0;

    for (int i = 0; i < minutes; i++)
    {
        // only add those customers which cant be serviced due to grumpy owner
        // track the max within the [minutes] frame
        if (grumpy[i] == 1)
            grumpPoints += cus[i];
    }

    int saved = grumpPoints;
    for (int i = 1; i < n - minutes + 1; i++)
    {
        int newComingPoint = i + minutes - 1;

        if (grumpy[i - 1] == 1)
            grumpPoints -= cus[i - 1];
        if (grumpy[newComingPoint] == 1)
            grumpPoints += cus[newComingPoint];

        saved = max(saved, grumpPoints);
    }

    return total + saved;
}

int main()
{
    vi cus{1, 0, 1, 2, 1, 1, 7, 5};
    vi grumpy{0, 1, 0, 1, 0, 1, 0, 1};
    int mins = 3;

    cout << maxSatisfied(cus, grumpy, mins) << endl;
}