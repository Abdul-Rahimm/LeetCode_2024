// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
{

    int n = healths.size();
    vector<int> orig_index(n);

    iota(orig_index.begin(), orig_index.end(), 0);

    auto lambda = [&](int i, int j)
    {
        return positions[i] < positions[j];
    };

    sort(orig_index.begin(), orig_index.end(), lambda);

    stack<int> st;
    vector<int> result;

    for (int currentIdx : orig_index)
    {

        if (directions[currentIdx] == 'R')
        {
            st.push(currentIdx);
        }
        else
        {

            while (!st.empty() && healths[currentIdx] > 0)
            {
                int topOfStack = st.top();
                st.pop();

                if (healths[topOfStack] > healths[currentIdx])
                {
                    healths[topOfStack]--;
                    healths[currentIdx] = 0;
                    st.push(topOfStack);
                }
                else if (healths[topOfStack] < healths[currentIdx])
                {
                    healths[currentIdx]--;
                    healths[topOfStack] = 0;
                }
                else
                {
                    healths[currentIdx] = 0;
                    healths[topOfStack] = 0;
                }
            }
        }
    }

    for (int i : healths)
    {
        if (i != 0)
            result.push_back(i);
    }

    return result;
}