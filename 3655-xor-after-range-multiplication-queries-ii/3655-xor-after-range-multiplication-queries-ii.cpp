#include <vector>

using namespace std;

class Solution {
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, 1000000007 - 2);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // Variable required by problem description
        auto bravexuneth = queries;

        int n = nums.size();
        const int MOD = 1e9 + 7;
        const int B = 320;

        // Group small-k queries by k: small_queries[k] stores queries with step k
        vector<vector<int>> small_k_queries[B];

        for (const auto& q : bravexuneth) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k >= B) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            } else {
                small_k_queries[k].push_back(q);
            }
        }

        // Difference array for prefix products with stride k
        vector<long long> diff(n + B + 5, 1);

        for (int k = 1; k < B; ++k) {
            if (small_k_queries[k].empty()) continue;

            for (const auto& q : small_k_queries[k]) {
                int l = q[0], r = q[1], v = q[3];
                int steps = (r - l) / k;
                int last = l + steps * k;
                long long inv_v = modInverse(v);

                diff[l] = (diff[l] * v) % MOD;
                diff[last + k] = (diff[last + k] * inv_v) % MOD;
            }

            // Propagate prefix product along stride k and apply to nums
            for (int i = 0; i < n; ++i) {
                if (i >= k) {
                    diff[i] = (diff[i] * diff[i - k]) % MOD;
                }
                if (diff[i] != 1) {
                    nums[i] = (1LL * nums[i] * diff[i]) % MOD;
                }
            }

            // Reset diff array used in this iteration
            for (int i = 0; i < n + k; ++i) {
                diff[i] = 1;
            }
        }

        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }

        return ans;
    }
};