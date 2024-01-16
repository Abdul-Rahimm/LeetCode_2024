// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> vec;
unordered_map<int, int> mp; // because we need to store index

bool insert(int val)
{
    if (mp.find(val) != mp.end())
        return false;

    vec.push_back(val);
    mp[val] = vec.size() - 1;

    return true;
}

bool remove(int val)
{
    if (mp.find(val) == mp.end())
        return false;

    int idx = mp[val];            // the index of the val to be removed
    int lastElement = vec.back(); // value of the last element
    vec.back() = val;             // place the value to be removed at the back

    vec[idx] = lastElement;
    vec.pop_back();
    mp.erase(val);

    return true;
}

int getRandom()
{
    int n = vec.size();
    int randomIndex = rand() % n;

    return vec[randomIndex];
}

int main()
{
    bool status1 = insert(1);
    cout << status1 << endl;

    bool status2 = remove(2);
    cout << status2 << endl;

    int number = getRandom();
    cout << number << endl;
}