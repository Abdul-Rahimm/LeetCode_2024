// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <iostream>

// Define your types for convenience
typedef std::vector<int> vi;

// Function to print a vector of integers
void print(const vi &nums)
{
    for (int i : nums)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// You can add more utility functions here

#endif // UTILS_H
