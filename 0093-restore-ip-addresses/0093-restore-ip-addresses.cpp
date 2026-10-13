#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> result;
        int n = s.length();
        
        // An IPv4 address requires between 4 and 12 digits
        if (n < 4 || n > 12) return result;

        std::vector<std::string> current_segments;
        backtrack(s, 0, current_segments, result);
        return result;
    }

private:
    void backtrack(const std::string& s, int start_idx, 
                   std::vector<std::string>& current_segments, 
                   std::vector<std::string>& result) {
        int segments_left = 4 - current_segments.size();
        int chars_left = s.length() - start_idx;

        // Prune if remaining characters cannot fit the remaining segments
        if (chars_left < segments_left || chars_left > segments_left * 3) {
            return;
        }

        // Base case: formed all 4 segments
        if (current_segments.size() == 4) {
            if (start_idx == s.length()) {
                result.push_back(current_segments[0] + "." + 
                                 current_segments[1] + "." + 
                                 current_segments[2] + "." + 
                                 current_segments[3]);
            }
            return;
        }

        // Try segments of length 1, 2, and 3
        for (int len = 1; len <= 3 && start_idx + len <= s.length(); ++len) {
            std::string part = s.substr(start_idx, len);
            
            // Numbers with leading zeros (e.g., "05") are invalid
            if (len > 1 && part[0] == '0') break;

            int val = std::stoi(part);
            if (val <= 255) {
                current_segments.push_back(part);
                backtrack(s, start_idx + len, current_segments, result);
                current_segments.pop_back();
            }
        }
    }
};