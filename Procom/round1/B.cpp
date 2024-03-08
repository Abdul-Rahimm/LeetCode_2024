bool solve()
{

    string s;
    cin >> s;

    int n = s.length();

    for (int i = 0; i < n; i++)
    {

        if (i % 2 == 0)
        {
            if (s[i] == 'L')
                return false;
        }
        else
        {
            if (s[i] == 'R')
                return false;
        }
    }

    return true;
}

int main()
{
    int t = 1;
    //    cin >> t;
    while (t--)
    {
        if (solve())
            cout << "Yes";
        else
            cout << "No";
    }
    return 0;
}