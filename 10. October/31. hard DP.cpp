typedef long long ll;
ll solve(ll ri, ll fi, vector<int> &robot, vector<ll> &positions, vector<vector<ll>> &dp)
{
    if (ri >= robot.size())
        return 0;
    if (fi >= positions.size())
        return 1e12;
    if (dp[ri][fi] != -1)
        return dp[ri][fi];

    ll take = abs(robot[ri] - positions[fi]) + solve(ri + 1, fi + 1, robot, positions, dp);
    ll skip = solve(ri, fi + 1, robot, positions, dp);

    return dp[ri][fi] = min(take, skip);
}

long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
{
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());

    vector<ll> positions;

    for (int i = 0; i < factory.size(); i++)
    {
        ll pos = factory[i][0];
        ll limit = factory[i][1];

        for (int j = 0; j < limit; j++)
        {
            positions.push_back(pos);
        }
    }

    int n = robot.size();
    int m = positions.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
    return solve(0, 0, robot, positions, dp);
}