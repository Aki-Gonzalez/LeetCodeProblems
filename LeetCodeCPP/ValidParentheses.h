#pragma once

#include <string>
#include <stack>

// https://leetcode.com/problems/valid-parentheses/

/*
    string consists of '(' ')' '{' '}' '[' ']'
    valid if the corresponding bracket is used in correct order: i.e: () is valid.
    (){}[] is valid
    (] is not valid
    assumption: ({}) would also be valid
    assumption: )() is invalid

    create table with valid open
    create table with valid closed
    iterate through string while remebering the previous char of the string
    if the current one is closed and of the same type move on
    else invalid

    pseudo code (first iteration):

    open[3] = ( [ {
    closed[3] = ) ] }
    stack<uint> openInString
    for i < string length
        if stack.empty
            for j < 3
                if s[i] == closed[j] // if string starts with a closed bracket: invalid.
                    return false
                else if s[i] == open[j] // find which char is used
                    stack.push(j)
                    continue
        else 
            for j < 3
                if s[i] == closed[j] && (j == stack.top)
                    // we have a valid parenthesis
                    stack.pop
                    continue
                for j < 3
                    if s[i] == open[j]
                        stack.push(j)

    // if last char is open, string is invalid
    for j < 3
        if string.last == closed[j]
            return false

    return true
*/

class Solution {
public:
    

    bool isValid(std::string s) {

        // ()[]{}
        typedef uint8_t ui;
        constexpr ui numChars = 3;
        char closed[numChars] = { ')', ']', '}' };
        char open[numChars] = { '(', '[', '{' };

        std::stack<ui> lastOpen;// C
        for (uint32_t i = 0; i < s.length(); i++)
        {
            if (lastOpen.empty())
            {
                for (ui j = 0; j < numChars; j++)
                {
                    // If we have no open and we find a closed string is invalid
                    if (s[i] == closed[j])
                    {
                        return false;
                    }
                    // If char is open, add to stack and continue
                    else if(s[i] == open[j])
                    {
                        lastOpen.push(j);
                        break;
                    }
                }
            }
            else
            {
                for (ui j = 0; j < numChars; j++)
                {
                    // Check if closed parenthesis: 
                    if (s[i] == closed[j])
                    {
                        // Does open on the stack match closed?
                        if (j == lastOpen.top())
                        {
                            lastOpen.pop();
                            break;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    // We have another open parenthesis
                    else if(s[i] == open[j])
                    {
                        lastOpen.push(j);
                        break;
                    }
                }
            }
        }

        // Check if string ends on an open parenthesis
        const size_t lastIndexOfString = s.length() - 1;
        for (ui i = 0; i < numChars; i++)
        {
            if (s[lastIndexOfString] == open[i])
                return false;
        }

        return lastOpen.empty();
    }
};