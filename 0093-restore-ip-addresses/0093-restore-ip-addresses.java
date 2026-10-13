import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> result = new ArrayList<>();
        int n = s.length();

        // An IPv4 address requires between 4 and 12 digits
        if (n < 4 || n > 12) {
            return result;
        }

        List<String> currentSegments = new ArrayList<>();
        backtrack(s, 0, currentSegments, result);
        return result;
    }

    private void backtrack(String s, int startIdx, 
                           List<String> currentSegments, 
                           List<String> result) {
        int segmentsLeft = 4 - currentSegments.size();
        int charsLeft = s.length() - startIdx;

        // Pruning checks
        if (charsLeft < segmentsLeft || charsLeft > segmentsLeft * 3) {
            return;
        }

        // Base case: all 4 segments collected
        if (currentSegments.size() == 4) {
            if (startIdx == s.length()) {
                result.add(String.join(".", currentSegments));
            }
            return;
        }

        // Try segments of length 1, 2, and 3
        for (int len = 1; len <= 3 && startIdx + len <= s.length(); len++) {
            String part = s.substring(startIdx, startIdx + len);

            // Reject leading zeros on segments longer than 1
            if (len > 1 && part.charAt(0) == '0') {
                break;
            }

            int val = Integer.parseInt(part);
            if (val <= 255) {
                currentSegments.add(part);
                backtrack(s, startIdx + len, currentSegments, result);
                currentSegments.remove(currentSegments.size() - 1);
            }
        }
    }
}