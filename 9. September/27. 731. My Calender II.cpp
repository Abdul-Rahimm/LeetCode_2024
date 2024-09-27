// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class MyCalendarTwo
{
    typedef pair<int, int> pr;
    typedef vector<pr> vi;
    typedef vector<vi> vii;

private:
    bool checkOverlap(pr booking, pr current)
    {
        int a1 = booking.first;
        int a2 = booking.second;
        int b1 = current.first;
        int b2 = current.second;

        if (max(a1, b1) < min(a2, b2))
            return true;

        return false;
    }

    pr findOverlappingRegion(pr booking, pr current)
    {
        int a1 = booking.first;
        int a2 = booking.second;
        int b1 = current.first;
        int b2 = current.second;

        return {max(a1, b1), min(a2, b2)};
    }

public:
    vi doubleBookings;
    vi bookings;
    MyCalendarTwo() {}

    bool book(int start, int end)
    {
        pr current{start, end};

        // check for triple booking
        for (pr booking : doubleBookings)
        {
            if (checkOverlap(booking, current))
                return false;
        }

        // check for double booking
        for (pr booking : bookings)
        {
            if (checkOverlap(booking, current))
                doubleBookings.push_back(
                    findOverlappingRegion(booking, current));
        }

        bookings.push_back(current);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */