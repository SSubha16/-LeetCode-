#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < n; ++i) {
            indices[nums[i]].push_back(i);
        }

        auto circularDist = [&](int i, int j) {
            int diff = abs(i - j);
            return min(diff, n - diff);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (int q : queries) {
            int val = nums[q];
            const auto& posList = indices[val];
            int m = posList.size();

            if (m == 1) {
                ans.push_back(-1);
                continue;
            }

            // Find index of q in posList
            auto it = lower_bound(posList.begin(), posList.end(), q);
            int idx = it - posList.begin();

            int leftNeighbor = posList[(idx - 1 + m) % m];
            int rightNeighbor = posList[(idx + 1) % m];

            ans.push_back(min(circularDist(q, leftNeighbor), circularDist(q, rightNeighbor)));
        }

        return ans;
    }
};