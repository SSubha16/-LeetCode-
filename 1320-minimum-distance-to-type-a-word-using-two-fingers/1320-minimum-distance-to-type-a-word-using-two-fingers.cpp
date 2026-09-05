#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
    int getDist(int a, int b) {
        if (a == 26) return 0; // Free placement
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

public:
    int minimumDistance(string word) {
        const int INF = 1e9;
        // dp[other] = min cost where one finger is at current character, 
        // and the other finger is at 'other' (26 means not placed yet).
        vector<int> dp(27, INF);
        dp[26] = 0; // Initially, the other finger hasn't been used yet

        for (int i = 0; i < (int)word.size() - 1; ++i) {
            int cur = word[i] - 'A';
            int next = word[i + 1] - 'A';
            int stepCost = getDist(cur, next);

            vector<int> nextDp(27, INF);

            for (int other = 0; other <= 26; ++other) {
                if (dp[other] == INF) continue;

                // Option 1: Move the same finger that typed cur to next
                nextDp[other] = min(nextDp[other], dp[other] + stepCost);

                // Option 2: Move the other finger to next (current finger becomes the other finger)
                nextDp[cur] = min(nextDp[cur], dp[other] + getDist(other, next));
            }

            dp = move(nextDp);
        }

        int ans = INF;
        for (int val : dp) {
            ans = min(ans, val);
        }
        return ans;
    }
};