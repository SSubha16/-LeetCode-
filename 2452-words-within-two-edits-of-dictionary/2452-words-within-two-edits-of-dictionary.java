import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        List<String> result = new ArrayList<>();
        int wordLength = queries[0].length();

        for (String query : queries) {
            for (String dictWord : dictionary) {
                int diffCount = 0;

                for (int i = 0; i < wordLength; i++) {
                    if (query.charAt(i) != dictWord.charAt(i)) {
                        diffCount++;
                        if (diffCount > 2) {
                            break; // Exceeded allowable edits
                        }
                    }
                }

                // If within 2 edits, add the query word and stop checking other dictionary words
                if (diffCount <= 2) {
                    result.add(query);
                    break;
                }
            }
        }

        return result;
    }
}