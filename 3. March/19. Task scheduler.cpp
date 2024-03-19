// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int leastInterval(vector<char> &tasks, int n)
{
    vector<int> array(26, 0);
    int count = 0;

    for (char i : tasks)
        array[i - 'A']++;

    sort(array.begin(), array.begin(), greater<int>());

    while (array[0] != 0)
    {
        int i = 0;
        for (i; i < 26; i++)
        {
            if (array[i] > 0)
            {
                count++;
                array[i]--;
            }
            else
                break;
        }

        if (array[0] != 0 && n != 1)
            count += min(n - i + 1, 0);
    }

    return count;
}

int main()
{
}