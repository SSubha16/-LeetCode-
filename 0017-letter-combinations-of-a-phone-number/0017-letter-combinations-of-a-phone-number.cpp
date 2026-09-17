#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return {};

        // Telephone keypad mapping indexed by digit character ('0' and '1' are empty)
        const std::vector<std::string> phoneMap = {
            "",     "",     "abc",  "def", 
            "ghi",  "jkl",  "mno",  "pqrs", 
            "tuv",  "wxyz"
        };

        std::vector<std::string> result;
        std::string current = "";

        backtrack(digits, 0, current, result, phoneMap);
        return result;
    }

private:
    void backtrack(const std::string& digits, 
                   int index, 
                   std::string& current, 
                   std::vector<std::string>& result, 
                   const std::vector<std::string>& phoneMap) {
        // Base case: formed a full combination
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        const std::string& letters = phoneMap[digits[index] - '0'];
        for (char ch : letters) {
            current.push_back(ch);
            backtrack(digits, index + 1, current, result, phoneMap);
            current.pop_back(); // Backtrack step
        }
    }
};