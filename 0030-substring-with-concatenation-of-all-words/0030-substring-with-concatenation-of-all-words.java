import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        if (s == null || words == null || words.length == 0 || s.length() == 0) {
            return result;
        }

        int wordLen = words[0].length();
        int numWords = words.length;
        int totalLen = wordLen * numWords;
        int n = s.length();

        if (n < totalLen) {
            return result;
        }

        Map<String, Integer> wordFreq = new HashMap<>();
        for (String w : words) {
            wordFreq.put(w, wordFreq.getOrDefault(w, 0) + 1);
        }

        // Iterate over all possible starting word alignments
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int right = offset;
            Map<String, Integer> currentCounts = new HashMap<>();

            while (right + wordLen <= n) {
                String word = s.substring(right, right + wordLen);
                right += wordLen;

                if (wordFreq.containsKey(word)) {
                    currentCounts.put(word, currentCounts.getOrDefault(word, 0) + 1);

                    // Shrink window if word frequency exceeds target
                    while (currentCounts.get(word) > wordFreq.get(word)) {
                        String leftWord = s.substring(left, left + wordLen);
                        currentCounts.put(leftWord, currentCounts.get(leftWord) - 1);
                        left += wordLen;
                    }

                    // Complete valid window matched
                    if (right - left == totalLen) {
                        result.add(left);
                    }
                } else {
                    // Reset window on seeing an unknown word
                    currentCounts.clear();
                    left = right;
                }
            }
        }

        return result;
    }
}