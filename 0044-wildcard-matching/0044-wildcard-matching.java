class Solution {
    public boolean isMatch(String s, String p) {
        int sLen = s.length();
        int pLen = p.length();
        
        int sIdx = 0;
        int pIdx = 0;
        int starIdx = -1;
        int sMatch = -1;

        while (sIdx < sLen) {
            // Case 1: Matching characters or '?'
            if (pIdx < pLen && (p.charAt(pIdx) == '?' || p.charAt(pIdx) == s.charAt(sIdx))) {
                sIdx++;
                pIdx++;
            } 
            // Case 2: Encounter '*' in pattern
            else if (pIdx < pLen && p.charAt(pIdx) == '*') {
                starIdx = pIdx;
                sMatch = sIdx;
                pIdx++; // Assume '*' matches 0 characters initially
            } 
            // Case 3: Mismatch, but a previous '*' exists -> backtrack
            else if (starIdx != -1) {
                pIdx = starIdx + 1;
                sMatch++;
                sIdx = sMatch;
            } 
            // Case 4: Mismatch with no preceding '*'
            else {
                return false;
            }
        }

        // Consume remaining '*' in pattern
        while (pIdx < pLen && p.charAt(pIdx) == '*') {
            pIdx++;
        }

        return pIdx == pLen;
    }
}