#include <string>
#include <vector>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        // Precompute factorials up to n - 1 and initialize the available digits list
        int fact = 1;
        std::vector<int> numbers;
        for (int i = 1; i < n; ++i) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n); // numbers = {1, 2, ..., n}

        // Convert k to 0-based indexing
        --k;

        std::string result = "";
        
        while (true) {
            // Determine the digit at the current position
            int index = k / fact;
            result += std::to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);

            // If all numbers have been placed, break
            if (numbers.empty()) {
                break;
            }

            // Update k and the factorial for the next position
            k %= fact;
            fact /= numbers.size();
        }

        return result;
    }
};