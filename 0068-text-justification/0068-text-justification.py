from typing import List

class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        result = []
        i = 0
        n = len(words)

        while i < n:
            j = i
            line_letters = 0

            # Determine how many words fit in the current line
            while j < n and line_letters + len(words[j]) + (j - i) <= maxWidth:
                line_letters += len(words[j])
                j += 1

            num_words = j - i

            # Case 1: Last line or line contains only one word (Left-justified)
            if j == n or num_words == 1:
                line = " ".join(words[i:j])
                line += " " * (maxWidth - len(line))
            # Case 2: Fully justified line
            else:
                total_spaces = maxWidth - line_letters
                base_spaces = total_spaces // (num_words - 1)
                extra_spaces = total_spaces % (num_words - 1)

                line_parts = []
                for k in range(i, j - 1):
                    line_parts.append(words[k])
                    # Give one extra space to the leftmost slots
                    spaces = base_spaces + (1 if (k - i) < extra_spaces else 0)
                    line_parts.append(" " * spaces)
                
                line_parts.append(words[j - 1])
                line = "".join(line_parts)

            result.append(line)
            i = j

        return result