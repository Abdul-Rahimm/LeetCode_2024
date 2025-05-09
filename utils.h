// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <iostream>
using namespace std;
// Define your types for convenience
typedef vector<int> vi;
typedef pair<int, int> P;
// Function to print a vector of integers
void print(const vi &nums)
{
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}
void print(vector<vector<char>> chars)
{
    int n = chars.size();
    int m = chars[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << chars[i][j] << " ";
        }
        cout << endl;
    }
}
void print(int start, const vi &nums)
{
    for (int i = start; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void print(priority_queue<int, vi, greater<int>> minHeap)
{
    while (minHeap.empty() != true)
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}
void print(priority_queue<int> maxHeap)
{
    while (maxHeap.empty() != true)
    {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;
}
void print(priority_queue<P, vector<P>, greater<P>> minHeap)
{
    while (minHeap.empty() != true)
    {
        P top = minHeap.top();
        cout << top.first << " " << top.second << endl;
        minHeap.pop();
    }
    cout << endl;
}
void print(priority_queue<P> maxHeap)
{
    while (maxHeap.empty() != true)
    {
        P top = maxHeap.top();
        cout << top.first << " " << top.second << endl;
        maxHeap.pop();
    }
    cout << endl;
}
void print(priority_queue<pair<int, char>> pq)
{
    while (pq.empty() != true)
    {
        pair<int, char> top = pq.top();
        cout << top.first << " " << top.second << " | ";
        pq.pop();
    }
    cout << endl;
}

void print(vector<pair<int, int>> vec)
{
    for (pair<int, int> pr : vec)
    {
        cout << pr.first << " " << pr.second << endl;
    }
    cout << endl;
}
void print(map<int, int> mp)
{
    for (auto row : mp)
    {
        cout << row.first << " : " << row.second << endl;
    }
}
void print(map<int, char> mp)
{
    for (auto row : mp)
    {
        cout << row.first << " : " << row.second << endl;
    }
}

void print(map<int, int, greater<int>> mp)
{
    for (auto row : mp)
    {
        cout << row.first << " : " << row.second << endl;
    }
}
void print(unordered_map<int, int> mp)
{
    for (auto row : mp)
    {
        cout << row.first << " : " << row.second << endl;
    }
}
void print(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void print(unordered_map<string, int> mp)
{
    for (auto row : mp)
    {
        cout << row.first << " : " << row.second << endl;
    }
}
void print(unordered_map<int, vector<pair<int, double>>> mp)
{
    for (auto row : mp)
    {
        int number = row.first;
        vector<pair<int, double>> pr = row.second;

        cout << number << " : ";
        for (auto pair : pr)
        {
            cout << pair.first << " " << pair.second << " | ";
        }
        cout << endl;
    }
}

void print(unordered_set<int> st)
{
    for (int i : st)
        cout << i << " ";
    cout << endl;
}
#endif
