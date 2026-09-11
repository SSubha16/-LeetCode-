#include <string>
#include <cmath>
#include <cstdlib>

class Solution {
public:
    int furthestDistanceFromOrigin(std::string moves) {
        int countL = 0;
        int countR = 0;
        int countBlank = 0;

        for (char c : moves) {
            if (c == 'L') {
                countL++;
            } else if (c == 'R') {
                countR++;
            } else {
                countBlank++;
            }
        }

        return std::abs(countL - countR) + countBlank;
    }
};