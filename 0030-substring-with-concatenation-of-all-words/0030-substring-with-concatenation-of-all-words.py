from collections import Counter

class Solution:
    def findSubstring(self, s: str, words: list[str]) -> list[int]:
        if not s or not words:
            return []
        
        word_len = len(words[0])
        num_words = len(words)
        total_len = word_len * num_words
        n = len(s)
        
        if n < total_len:
            return []
        
        word_freq = Counter(words)
        result = []
        
        # Iterate over all possible starting word alignments
        for offset in range(word_len):
            left = offset
            right = offset
            current_counts = Counter()
            
            while right + word_len <= n:
                word = s[right:right + word_len]
                right += word_len
                
                if word in word_freq:
                    current_counts[word] += 1
                    
                    # If this word occurs more times than required, contract from the left
                    while current_counts[word] > word_freq[word]:
                        left_word = s[left:left + word_len]
                        current_counts[left_word] -= 1
                        left += word_len
                    
                    # If window covers all words, record the starting index
                    if right - left == total_len:
                        result.append(left)
                else:
                    # Reset the window if an invalid word is encountered
                    current_counts.clear()
                    left = right
                    
        return result