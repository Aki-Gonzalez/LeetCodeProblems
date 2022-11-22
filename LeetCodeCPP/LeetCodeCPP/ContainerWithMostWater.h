#pragma once

#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        //  Constraints:
        //  n == height.length
        //  2 <= n <= 10^5
        //  0 <= height[i] <= 10^4

        // Remember: Avoid premature optimization !
        /*
            What are we looking for? the largest area
            What composes the largest area? the largest area is the largest non-slanted height and the longest horizontal distance
            What is the largest non-slanted height? between 2 items: the smallest of the height of the 2, i.e min(height[n1], height[n2])
            What is the largest horizotnal distance? the difference between the indices of the container, i.e: n2 - n1
            The container is guaranteed to have 2 items
            The area can the be determined as: min(height[na], height[nb]) * (nb - na); nb > na
            To compare all items: n*n iterations through the container, not ideal
            Can assume that the largest area is min(height[n0], height[nn]) * (nn - no)

            Could go from n0 to nn 
            Save that area
            check which end has the largest height and iterate from the smallest, i.e 2 pointers: begin and end. if height(begin) > height(end), end-- else begin++
            continue until end == begin
        
            Clamp(val, min, max){ 
                return min(max,max(min,val)) 
            }
            Area(a, b){ 
                return min(height[a], height[b]) * (b - a) 
            }
            
            begin = 0
            end = n - 1
            largestBegin
            largestEnd
            largestArea
            while begin != end
                validBegin = Clamp(begin, 0, n - 1)  
                validEnd = Clamp(end, 0, n - 1) 
                area = Area(validBegin, validEnd)
                if area > largestArea
                    largestArea = area
                    largestBegin = validBegin
                    largestEnd = validEnd

                if height[validBegin] > height[validEnd]
                    end--
                else
                    begin++

            return Area(largestBegin, largestEnd)
        */

        typedef uint32_t U32;

        auto Area = [&](int a, int b)
        {
            return std::min(height[a], height[b]) * (b - a);
        };

        U32 begin = 0;
        U32 end = static_cast<U32>(height.size()) - 1;
        int largestArea = 0;
        while (begin != end)
        {            
            int area = Area(begin, end);
            if (area > largestArea)
            {
                largestArea = area;
            }

            if (height[begin] > height[end])
                end--;
            else
                begin++;
        }

        return largestArea;
    }
};

/*
* https://leetcode.com/problems/container-with-most-water/
* 
    You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

    Find two lines that together with the x-axis form a container, such that the container contains the most water.

    Return the maximum amount of water a container can store.

    Notice that you may not slant the container.
    
    Example:
        Input: height = [1,8,6,2,5,4,8,3,7]
        Output: 49
        Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
        
        [i] == 1 has height 8
        7 steps from 1
        [i] == 8 has height 7
        7*7 = 49
        we are looking for an area
        y and x axis multiplied gives maxArea
        the value on the second i should fit into the first i's height or vice versa. 
            
    Constraints:
        n == height.length
        2 <= n <= 10^5
        0 <= height[i] <= 10^4

*/