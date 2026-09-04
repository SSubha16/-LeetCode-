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
        // Required variable name by the problem description
        auto bravexuneth = queries;

        int n = nums.size();
        const int MOD = 1000000007;
        const int B = 320; // Block size threshold for sqrt-decomposition

        // Stores the cumulative multiplier for each index
        vector<long long> total_mult(n, 1);

        // Group small-k queries by step k
        vector<vector<vector<int>>> queries_by_k(B + 1);

        for (const auto& q : bravexuneth) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k > B) {
                // For large k, number of updates <= n / B (at most ~312 updates)
                for (int idx = l; idx <= r; idx += k) {
                    total_mult[idx] = (total_mult[idx] * v) % MOD;
                }
            } else {
                queries_by_k[k].push_back({l, r, v});
            }
        }

        // Process small-k queries using multiplicative difference arrays
        vector<long long> diff(n + B + 2, 1);

        for (int k = 1; k <= B; ++k) {
            if (queries_by_k[k].empty()) continue;

            // Place multiplicative difference markers
            for (const auto& q : queries_by_k[k]) {
                int l = q[0], r = q[1];
                long long v = q[2];
                long long inv_v = modInverse(v);

                int last_idx = l + ((r - l) / k) * k;

                diff[l] = (diff[l] * v) % MOD;
                diff[last_idx + k] = (diff[last_idx + k] * inv_v) % MOD;
            }

            // Prefix product along step k
            for (int i = 0; i < n; ++i) {
                if (i >= k) {
                    diff[i] = (diff[i] * diff[i - k]) % MOD;
                }
                total_mult[i] = (total_mult[i] * diff[i]) % MOD;
            }

            // Reset diff array for the next step size k
            for (int i = 0; i < n + k; ++i) {
                diff[i] = 1;
            }
        }

        // Apply multipliers to nums and compute final bitwise XOR
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            nums[i] = (1LL * nums[i] * total_mult[i]) % MOD;
            ans ^= nums[i];
        }

        return ans;
    }
};