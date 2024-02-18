#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
void print(vector<vector<int>> nums)
{
    for (vector<int> row : nums)
    {
        for (int i : row)
            cout << i << " ";
        cout << endl;
    }
}
int mostBooked(int n, vector<vector<int>> &meetings, vector<int> &rooms, vector<int> &freq)
{
    sort(meetings.begin(), meetings.end());

    for (vector<int> row : meetings)
    {
        int start = row[0];
        int end = row[1];
        bool roomAlloted = false;

        // for the ith meeting. find which room is available
        for (int i = 0; i < n; i++)
        {

            // if some room is not alloted or alloted but old meet ends before new starts
            if (rooms[i] == -1 || rooms[i] > 0 && rooms[i] <= start)
            {
                // assign this room when the meeting will get over
                rooms[i] = end;
                freq[i]++;
                roomAlloted = true;
                break;
            }
        }
        if (roomAlloted)
            continue;

        // room not alloted
        int duration = end - start;

        // if all the rooms are busy - find earliest endtime time - clash = lowest room
        int lowestIndex = INT_MAX;
        int lowestRoom;
        for (int i = 0; i < n; i++)
        {
            if (rooms[i] < lowestIndex)
            {
                lowestIndex = rooms[i];
                lowestRoom = i;
            }
        }

        rooms[lowestRoom] += duration;
        freq[lowestRoom]++;
    }

    int highestFreq = 0;
    int ans;
    for (int i = 0; i < n; i++)
    {
        if (freq[i] > highestFreq)
        {
            highestFreq = freq[i];
            ans = i;
        }
    }

    return ans;
}

int main()
{
    fastio;
    int n = 3;

    vector<vector<int>> nums{{1, 20}, {3, 5}, {2, 10}, {4, 9}, {6, 8}};
    vector<int> rooms(n, -1);
    vector<int> freq(n, 0);
    cout << mostBooked(n, nums, rooms, freq) << endl;

    return 0;
}