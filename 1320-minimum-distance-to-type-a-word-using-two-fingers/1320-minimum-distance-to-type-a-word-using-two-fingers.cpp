#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
    int getDist(int a, int b) {
        if (a == 26 || b == 26) return 0; // 26 represents a free initial placement
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

public:
    int minimumDistance(string word) {
        // dp[j] stores the minimum cost when one finger is at the last typed letter,
        // and the other finger is at letter 'j' (26 means not placed yet).
        const int INF = 1e9;
        vector<int> dp(27, INF);
        
        // After typing the first character (word[0]), one finger is at word[0],
        // and the other finger has not been placed yet (state 26) at cost 0.
        dp[26] = 0;

        for (int i = 1; i < word.length(); ++i) {
            int prev = word[i - 1] - 'A';
            int curr = word[i] - 'A';
            vector<int> next_dp(27, INF);

            for (int j = 0; j <= 26; ++j) {
                if (dp[j] == INF) continue;

                // Option 1: Move the same finger (from prev to curr)
                // The other finger remains at j.
                next_dp[j] = min(next_dp[j], dp[j] + getDist(prev, curr));

                // Option 2: Move the other finger (from j to curr)
                // The new "other" finger is left at prev.
                next_dp[prev] = min(next_dp[prev], dp[j] + getDist(j, curr));
            }

            dp = move(next_dp);
        }

        return *min_element(dp.begin(), dp.end());
    }
};