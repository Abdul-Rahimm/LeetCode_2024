// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int pivotInteger(int n)
{
    int i = 1, j = n;
    int left = i, right = j;

    while (i != j && i < j)
    {

        if (left < right)
            while (left < right)
            {
                i++;
                left += i;
            }
        else if (right < left)
            while (right < left)
            {
                j--;
                right += j;
            }
        else
        {
            // both are same
            j--;
            i++;

            left += i;
            right += j;

            if (left == right)
                return i;
            else
                continue;
        }
    }

    return -1;
}

int main()
{

    cout << pivotInteger(8) << endl;
}