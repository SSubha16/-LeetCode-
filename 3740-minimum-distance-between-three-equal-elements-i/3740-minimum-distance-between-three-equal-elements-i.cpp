#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        // Map each value to the list of its indices
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < nums.size(); ++i) {
            pos[nums[i]].push_back(i);
        }

        int min_diff = INT_MAX;

        // Check 3 consecutive occurrences for each distinct value
        for (const auto& [val, indices] : pos) {
            if (indices.size() >= 3) {
                for (size_t i = 0; i + 2 < indices.size(); ++i) {
                    min_diff = min(min_diff, indices[i + 2] - indices[i]);
                }
            }
        }

        return (min_diff == INT_MAX) ? -1 : 2 * min_diff;
    }
};