#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int i = s.length() - 1;
        int length = 0;

        // 1. Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // 2. Count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};