#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // Frequency map for characters in t
        vector<int> target_freq(128, 0);
        for (char c : t) {
            target_freq[c]++;
        }

        // Sliding window tracking
        vector<int> window_freq(128, 0);
        int matched = 0;             // Total required characters matched so far
        int required = t.length();   // Total characters needed from t

        int min_len = INT_MAX;
        int start_idx = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char curr = s[right];
            window_freq[curr]++;

            // If current char is still needed to satisfy count in t
            if (target_freq[curr] > 0 && window_freq[curr] <= target_freq[curr]) {
                matched++;
            }

            // Once all characters from t are present in the window, shrink from left
            while (matched == required) {
                int current_window_len = right - left + 1;
                if (current_window_len < min_len) {
                    min_len = current_window_len;
                    start_idx = left;
                }

                char left_char = s[left];
                window_freq[left_char]--;

                // If removing left_char violates the requirements for t
                if (target_freq[left_char] > 0 && window_freq[left_char] < target_freq[left_char]) {
                    matched--;
                }

                left++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};