#include <vector>
#include <unordered_map>
#include <numeric>

class Solution {
public:
    std::vector<long long> distance(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<long long> arr(n, 0);
        std::unordered_map<int, std::vector<int>> indices;

        // Group indices by value
        for (int i = 0; i < n; ++i) {
            indices[nums[i]].push_back(i);
        }

        // Calculate distances for each group
        for (const auto& [val, idx_list] : indices) {
            int k = idx_list.size();
            if (k <= 1) continue;

            long long total_sum = 0;
            for (int idx : idx_list) {
                total_sum += idx;
            }

            long long left_sum = 0;
            for (int i = 0; i < k; ++i) {
                long long curr = idx_list[i];
                long long right_sum = total_sum - left_sum - curr;

                long long left_contrib = (long long)i * curr - left_sum;
                long long right_contrib = right_sum - (long long)(k - 1 - i) * curr;

                arr[curr] = left_contrib + right_contrib;
                left_sum += curr;
            }
        }

        return arr;
    }
};