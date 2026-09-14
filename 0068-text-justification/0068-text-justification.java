import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new ArrayList<>();
        int i = 0;
        int n = words.length;

        while (i < n) {
            int j = i;
            int lineLettersLength = 0;

            // Greedily pack words that fit into maxWidth with at least 1 space between them
            while (j < n && lineLettersLength + words[j].length() + (j - i) <= maxWidth) {
                lineLettersLength += words[j].length();
                j++;
            }

            StringBuilder sb = new StringBuilder();
            int numWords = j - i;
            int totalSpaces = maxWidth - lineLettersLength;

            // Case 1: Last line or a line with only one word -> Left-justified
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    sb.append(words[k]);
                    if (k < j - 1) {
                        sb.append(" ");
                    }
                }
                // Pad remaining spaces to the right
                while (sb.length() < maxWidth) {
                    sb.append(" ");
                }
            } else {
                // Case 2: Middle line with multiple words -> Fully-justified
                int spacesPerSlot = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);

                for (int k = i; k < j; k++) {
                    sb.append(words[k]);
                    if (k < j - 1) {
                        int spacesToApply = spacesPerSlot + (k - i < extraSpaces ? 1 : 0);
                        for (int s = 0; s < spacesToApply; s++) {
                            sb.append(" ");
                        }
                    }
                }
            }

            result.add(sb.toString());
            i = j; // Move to the next batch of words
        }

        return result;
    }
}