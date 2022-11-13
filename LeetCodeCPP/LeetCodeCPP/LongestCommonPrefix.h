#pragma once

#include <string>
#include <vector>

// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        int minCommonLength = INT_MAX;
        for (auto& s : strs)
        {
            minCommonLength = std::min(minCommonLength, static_cast<int>(s.length()));
        }

        // There is only 1 string
        const std::string& firstString = strs[0];
        if (strs.size() < 2)
            return firstString;

        int commonPrefixIndex = -1;
        for (int i = 0; i < minCommonLength; i++)
        {
            const char& currentChar = firstString[i];
            int matches = 1;
            for (int j = 1; j < strs.size(); j++)
            {
                const std::string& s = strs[j];
                if (s[i] == currentChar)
                {
                    matches++;
                }
                else
                {
                    break;
                }
            }

            if (matches == strs.size())
            {
                commonPrefixIndex++;
            }
            else
            {
                break;
            }
        }

        if (commonPrefixIndex >= 0)
        {
            return firstString.substr(0, commonPrefixIndex + 1);
        }
        else
        {
            return std::string();
        }
    }
};