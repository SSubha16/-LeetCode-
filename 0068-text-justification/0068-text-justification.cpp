#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLetters = 0;

            // Find how many words fit in the current line
            // Each word after the first requires at least 1 space: (j - i)
            while (j < n && lineLetters + words[j].length() + (j - i) <= maxWidth) {
                lineLetters += words[j].length();
                j++;
            }

            int numWords = j - i;
            std::string line = "";

            // Case 1: Last line OR line contains only one word (Left-justified)
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += " ";
                    }
                }
                // Pad remaining spaces on the right
                line.append(maxWidth - line.length(), ' ');
            } 
            // Case 2: Fully justified line
            else {
                int totalSpaces = maxWidth - lineLetters;
                int baseSpaces = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        // Distribute base spaces plus 1 extra space to the leftmost slots
                        int spacesToApply = baseSpaces + (k - i < extraSpaces ? 1 : 0);
                        line.append(spacesToApply, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j; // Move to the start of the next line
        }

        return result;
    }
};