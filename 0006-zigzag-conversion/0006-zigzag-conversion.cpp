#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // Base case: no zigzag pattern possible
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Create a vector of strings for each row
        vector<string> rows(min((int)s.length(), numRows));
        int curRow = 0;
        bool goingDown = false;

        // Traverse the string
        for (char c : s) {
            rows[curRow] += c;
            // Reverse direction if we hit the top or bottom row
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows
        string result;
        for (const string& row : rows) {
            result += row;
        }
        return result;
    }
};