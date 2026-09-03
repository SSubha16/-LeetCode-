#include <vector>
#include <string>
#include <string_view>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int sLen = s.length();

        if (sLen < totalLen) return result;

        // Count frequency of each word in the target list
        std::unordered_map<std::string_view, int> wordFreq;
        for (const auto& w : words) {
            wordFreq[w]++;
        }

        std::string_view sv(s);

        // Run sliding window starting from each possible offset within a word length
        for (int offset = 0; offset < wordLen; ++offset) {
            int left = offset;
            int right = offset;
            int count = 0;
            std::unordered_map<std::string_view, int> windowFreq;

            while (right + wordLen <= sLen) {
                // Extract the next token
                std::string_view sub = sv.substr(right, wordLen);
                right += wordLen;

                auto it = wordFreq.find(sub);
                if (it != wordFreq.end()) {
                    windowFreq[sub]++;
                    count++;

                    // If the current word appears more times than required, shrink from left
                    while (windowFreq[sub] > it->second) {
                        std::string_view leftSub = sv.substr(left, wordLen);
                        windowFreq[leftSub]--;
                        count--;
                        left += wordLen;
                    }

                    // Window matched all words exactly
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Reset the window if the word is not in the list
                    windowFreq.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};