class Solution {
    public int numDecodings(String s) {
        if (s == null || s.isEmpty() || s.charAt(0) == '0') {
            return 0;
        }

        int n = s.length();
        // prev2 represents dp[i - 2], prev1 represents dp[i - 1]
        int prev2 = 1; // Base case for empty prefix: dp[0] = 1
        int prev1 = 1; // Base case for length 1 prefix: dp[1] = 1 (since s[0] != '0')

        for (int i = 2; i <= n; i++) {
            int current = 0;

            // Single-digit decode: s[i - 1] must be between '1' and '9'
            int oneDigit = s.charAt(i - 1) - '0';
            if (oneDigit >= 1 && oneDigit <= 9) {
                current += prev1;
            }

            // Two-digit decode: s[i - 2..i - 1] must be between 10 and 26
            int twoDigits = Integer.parseInt(s.substring(i - 2, i));
            if (twoDigits >= 10 && twoDigits <= 26) {
                current += prev2;
            }

            // Slide the window forward
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
}