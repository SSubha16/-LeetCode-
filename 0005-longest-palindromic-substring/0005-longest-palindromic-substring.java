class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.length() < 2) {
            return s;
        }

        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            // Expand around single character center (odd length)
            int len1 = expandAroundCenter(s, i, i);
            // Expand around two character center (even length)
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = Math.max(len1, len2);

            if (len > maxLen) {
                maxLen = len;
                // Calculate starting index from center and length
                start = i - (len - 1) / 2;
            }
        }

        return s.substring(start, start + maxLen);
    }

    private int expandAroundCenter(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        // Length of the valid palindrome
        return right - left - 1;
    }
}