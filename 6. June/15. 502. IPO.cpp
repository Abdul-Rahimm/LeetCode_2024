// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> P;
void print(priority_queue<P, vector<P>, greater<P>> capital)
{
    while (capital.empty() == false)
    {
        P pr = capital.top();
        capital.pop();

        cout << pr.first << " " << pr.second << endl;
    }
    cout << endl;
}
void print(priority_queue<P> capital)
{
    while (capital.empty() == false)
    {
        P pr = capital.top();
        capital.pop();

        cout << pr.first << " " << pr.second << endl;
    }
    cout << endl;
}

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capitals)
{
    int n = profits.size();
    // i will make two heaps. one min heap for capital. one max heap for profit

    priority_queue<P, vector<P>, greater<P>> capital;
    priority_queue<P> profit;

    for (int i = 0; i < n; i++)
    {
        capital.push({capitals[i], profits[i]});
        profit.push({profits[i], capitals[i]});
    }

    while (k-- && n--)
    {

        if (w < profit.top().second)
        {
            // pick from capital
            w += capital.top().second;
            capital.pop();
        }
        else
        {
            if (w >= capital.top().first)
            {
                // pick from profit
                w += profit.top().first;
                profit.pop();
            }
        }
    }

    return w;
}

int main()
{
    vi profits{1, 2, 3};
    vi capitals{1, 1, 2};
    int answer = findMaximizedCapital(1, 0, profits, capitals);
    cout << answer << endl;
}