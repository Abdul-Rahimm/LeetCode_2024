#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
vector<int> nums;
int n;

int solve(int i, int bricks, int ladders)
{
    if (i >= n || (bricks <= 0 && ladders <= 0))
        return 0;

    // no need to utilize any ladder of brick. explore ahead
    if (nums[i] >= nums[i + 1])
        return 1 + solve(i + 1, bricks, ladders);

    // else condition
    // choice between ladder brick - which will take u farther - burj khalifa

    int brick = 0;
    int requiredBricks = INT_MAX;
    if (i < n - 1)
        requiredBricks = nums[i + 1] - nums[i];

    if (bricks >= requiredBricks)
    {
        // aagay wali building is barhee - utnay bricks hain bhi k nai
        brick = 1 + solve(i + 1, bricks - requiredBricks, ladders);
    }

    int ladder = 0;

    if (ladders > 0)
        ladder = 1 + solve(i + 1, bricks, ladders - 1);

    return max(brick, ladder);
}
int furthestBuilding(vector<int> &heights, int bricks, int ladders)
{
    nums = heights;
    n = heights.size();

    return solve(0, bricks, ladders);
}

int furthestBuilding(vector<int> &heights, int bricks, int ladders)
{
    int n = heights.size();

    priority_queue<int> pq;

    int i = 0;
    for (; i < n - 1; i++)
    {
        if (heights[i] >= heights[i + 1])
        {
            continue;
        }

        int diff = heights[i + 1] - heights[i];
        if (diff <= bricks)
        {
            bricks -= diff;
            pq.push(diff); // I used diff bricks here (keep track of it)
        }
        else if (ladders > 0)
        {
            if (!pq.empty())
            {
                int max_bricks_past = pq.top();
                if (max_bricks_past > diff)
                {
                    // it means i unneccasrily used huge bricks in past. Let's get it back
                    bricks += max_bricks_past;
                    pq.pop();
                    pq.push(diff);
                    bricks -= diff;
                }
            }
            ladders--; // either used in past or present
        }
        else
        {
            break;
        }
    }
    return i;
}

int main()
{
    fastio;
    vector<int> nums{14, 3, 19, 3};
    cout << furthestBuilding(nums, 17, 0) << endl;

    // int t;
    // cin >> t;

    // vector<int> nums(t);

    // for (int i = 0; i < t; i++)
    //     cin >> nums[i];

    // int bricks, ladders;
    // cin >> bricks >> ladders;

    // cout << furthestBuilding(nums, bricks, ladders) << endl;
    return 0;
}