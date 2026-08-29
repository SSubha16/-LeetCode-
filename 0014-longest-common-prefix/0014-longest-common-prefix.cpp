#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";

        // Iterate character by character through the first string
        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            
            // Compare the character across all other strings
            for (int j = 1; j < strs.size(); ++j) {
                // If index exceeds current string length or characters mismatch
                if (i == strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};