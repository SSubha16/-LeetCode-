#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);
        int level = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string currentWord = q.front();
                q.pop();

                for (int j = 0; j < currentWord.length(); j++) {
                    char originalChar = currentWord[j];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue;
                        currentWord[j] = c;

                        if (currentWord == endWord) {
                            return level + 1;
                        }

                        if (wordSet.find(currentWord) != wordSet.end()) {
                            q.push(currentWord);
                            wordSet.erase(currentWord); // Mark as visited
                        }
                    }
                    currentWord[j] = originalChar; // Restore original character
                }
            }
            level++;
        }

        return 0;
    }
};