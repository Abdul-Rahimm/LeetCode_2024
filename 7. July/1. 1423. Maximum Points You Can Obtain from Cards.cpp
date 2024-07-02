// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int maxScore(vector<int> &points, int k)
{
    int sum = 0;
    int n = points.size();
    int i = 0, j = n - 1;

    while (k--)
    {
        if (points[i] == points[j])
        {
            sum += points[i];

            if (j > 0 && i < n - 1)
            {
                if (points[j - 1] > points[i + 1])
                {
                    j--;
                }
                else
                    i++;
            }
        }
        else if (points[i] > points[j])
        {
            sum += points[i];
            i++;
        }
        else
        {
            sum += points[j];
            j--;
        }
    }

    return sum;
}

int main()
{
    vector<int> points{11, 49, 100, 20, 86, 29, 72};
    cout << maxScore(points, 4) << endl;
}