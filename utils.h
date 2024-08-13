// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <iostream>
using namespace std;
// Define your types for convenience
typedef vector<int> vi;

// Function to print a vector of integers
void print(const vi &nums)
{
    for (int i : nums)
    {
        cout << i << " ";
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
// function overloading
#endif
