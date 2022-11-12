#pragma once

#include <string>

// https://leetcode.com/problems/palindrome-number/

/*
    if x is negative it cannot be a palindrome (-121 != 121-)
    return false

    a number is a palindrome if it can be read the same backwards as forwards. 121, true. 123, false.
    how do we read an integer backwards?
    a string can be reversed, if the int is fed into a string and then converted back it could be checked
    string xAsString = to_string(x)
    reverse xAsString
    int reversed = convert xAsString to int

    return reversed == x
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        std::string xAsString = std::to_string(x);
        std::reverse(xAsString.begin(), xAsString.end());
        long long reversed = std::stoll(xAsString);
        return reversed == x;
    }
};