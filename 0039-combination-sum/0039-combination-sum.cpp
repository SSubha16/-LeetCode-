#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> results;
        std::vector<int> current;
        
        // Sorting enables early stopping in the loop
        std::sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, current, results);
        return results;
    }

private:
    void backtrack(const std::vector<int>& candidates, int remain, int start,
                   std::vector<int>& current, std::vector<std::vector<int>>& results) {
        if (remain == 0) {
            results.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Since candidates are sorted, all subsequent values will also exceed remain
            if (candidates[i] > remain) {
                break;
            }

            current.push_back(candidates[i]);
            // Stay at index `i` because elements can be reused
            backtrack(candidates, remain - candidates[i], i, current, results);
            current.pop_back(); // Backtrack
        }
    }
};