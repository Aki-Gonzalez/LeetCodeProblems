#pragma once

#include <string>
#include <vector>

// https://leetcode.com/problems/zigzag-conversion/

/*
    Input: s = "PAYPALISHIRING", numRows = 4
    Output: "PINALSIGYAHRPI"
    Explanation:
    P     I    N
    A   L S  I G
    Y A   H R
    P     I

    Input: s = "PAYPALISHIRING", numRows = 3
    Output: "PAHNAPLSIIGYIR"
    Explanation:
    P   A   H   N
    A P L S I I G
    Y   I   R

    Input: s = "PAYPALISHIRING", numRows = 2
    Output: "PYAIHRNAPLSIIG"
    Explanation:
    P Y A I H R N
    A P L S I I G

    Input: s = "PAYPALISHIRING", numRows = 5
    Output: "PHASIYIRPLIGAN"
    Explanation:
    P       H
    A     S I
    Y   I   R
    P L     I G
    A       N

    Input: s = "PAYPALISHIRINGTODAY", numRows = 9
    Output: "PDAOAYTYPGANLIIRSIH"
    Explanation:
    P         D 
    A       O A
    Y      T  Y
    P     G
    A    N
    L   I
    I  R
    S I
    H

    Pattern to get first character of next column: (col + numRows + numRows - 2), string[col + row + numRows + numRows-2] 
    row 1 and row numRows have maxChar == numColumns
    1 > rows < numRows have maxChar == numColums + numColumns 

    int numColums = string.length / numRows
    string output
    for(column)
        for(row)
            int inStringIndex = column + row + numRows + numRows - 2
            if(Overflows(inStringIndex))
                continue
            output.append(inString[inStringIndex])

    Pattern to get diagonal characters: columnIndex - (row * 2)
    if(diagonalIndex == prevColumnIndex || diagonalIndex == columnIndex)
        no diagonal character
*/

class Solution {
public:
    
    std::string convert(std::string s, int numRows) {

        if(numRows == 1)
            return s;

        typedef unsigned int ui;

        auto Overflows = [](const int index, const int size)
        {
            return index < 0 || index >= size;
        };
        
        const int stringLength = s.length();
        const ui columns = static_cast<ui>(stringLength / numRows);
        const ui numColumns = columns < 1 ? 1 : columns;
        std::string zigzag;
        zigzag.resize(stringLength);

        ui zigzagIndex = 0;
        ui prevColumnIndex = stringLength;
        for (ui row = 0; row <= numRows; row++)
        {
            for (ui column = 0; column <= numColumns; column++)
            {
                const ui columnIndex = row + column * ((2 * numRows) - 2);
                const ui diagonalIndex = columnIndex - (row * 2);
                if (diagonalIndex != prevColumnIndex 
                &&  diagonalIndex != columnIndex
                &&  Overflows(diagonalIndex, stringLength) == false)
                {
                    zigzag[zigzagIndex] = s[diagonalIndex];
                    zigzagIndex++;
                }

                if (columnIndex == prevColumnIndex)
                    continue;
                prevColumnIndex = columnIndex;

                if (Overflows(columnIndex, stringLength))
                    continue;
                if (zigzagIndex >= stringLength)
                    break;
                zigzag[zigzagIndex] = s[columnIndex];
                zigzagIndex++;
            }
        }
        return zigzag;
    }
};