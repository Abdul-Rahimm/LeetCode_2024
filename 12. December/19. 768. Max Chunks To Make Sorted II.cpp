class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();

        stack<int> st;
        int mx = 0;

        for (int i : arr)
        {
            mx = max(mx, i);

            while (!st.empty() && st.top() > i)
            {
                cout << st.top() << " " << i << endl;
                st.pop();
            }

            st.push(mx);
        }

        return st.size();
    }
};