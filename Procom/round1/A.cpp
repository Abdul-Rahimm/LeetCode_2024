void solve()
{

    vector<int> nums;

    int q;
    cin >> q;

    while (q--)
    {
        int i;
        cin >> i;

        int c;
        cin >> c;

        if (i == 1)
        {
            nums.push_back(c);
        }
        else
        {
            int size = nums.size();

            cout << nums[size - c] << endl;
        }
    }
}

int main()
{
    int t = 1;
    //    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}