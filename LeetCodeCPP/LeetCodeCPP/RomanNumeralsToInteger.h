#pragma once

#include <string>

// https://leetcode.com/problems/roman-to-integer/

int ConversionTable(const char c){
    if(c == 'I'){
        return 1;
    }
    if(c == 'V'){
        return 5;
    }
    if(c == 'X'){
        return 10;
    }
    if(c == 'L'){
        return 50;
    }
    if(c == 'C'){
        return 100;
    }
    if(c == 'D'){
        return 500;
    }
    if(c == 'M'){
        return 1000;
    }
    return 0;
}

int CheckRelation(const int cur, const int next)
{
    auto relationCurNext = [](int cur, int next, int a, int b, int c) { 
        return cur == a && (next == b || next == c); 
    };
    
    if (relationCurNext(cur, next, 1, 5, 10)
    ||  relationCurNext(cur, next, 10, 50, 100)
    ||  relationCurNext(cur, next, 100, 500, 1000))
    {
        return -cur;
    }
    return cur;
}

class Solution {
public:
    int romanToInt(std::string s) {

        const size_t size = s.size();
        int sum = 0;    
        for (unsigned int i = 0; i < size; i++)
        {
            const int cur = ConversionTable(s[i]);
            int next = 0;
            if ((i + 1) < size)
            {
                next = ConversionTable(s[i + 1]);
            }
            sum += CheckRelation(cur, next);
        }

        return sum;
    }
};
