#include <string>
#include <vector>

class Solution {
public:
    std::string intToRoman(int num) {
        const std::vector<std::pair<int, std::string>> val_map = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };
        
        std::string result = "";
        for (const auto& [value, symbol] : val_map) {
            if (num == 0) break;
            
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        
        return result;
    }
};