// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool lemonadeChange(vector<int> &bills)
{
    vector<int> change(11, 0); // 0-10

    int n = bills.size();
    for (int i = 0; i < n; i++)
    {

        if (bills[i] == 5)
        {
            change[5]++;
        }
        else if (bills[i] == 10)
        {
            change[10]++;

            if (change[5] > 0)
                change[5]--;
            else
                return false;
        }
        else
        {
            if (change[5] > 0 && change[10] > 0)
            {
                change[5]--;
                change[10]--;
            }
            else if (change[5] >= 3)
            {
                change[5] -= 3;
            }
            else
                return false;
        }
    }

    return true;
}
int main()
{
    vector<int> bills{5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 5};
    cout << lemonadeChange(bills) << endl;
}