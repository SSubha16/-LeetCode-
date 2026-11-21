#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return {};

        // Phase 1: BFS to find shortest distances and build parent DAG
        unordered_map<string, vector<string>> parents;
        unordered_map<string, int> dist;
        queue<string> q;
        
        dist[beginWord] = 0;
        q.push(beginWord);
        bool found = false;
        int L = beginWord.size();

        while (!q.empty() && !found) {
            int sz = q.size();
            for (int k = 0; k < sz; ++k) {
                string curr = q.front();
                q.pop();
                int currDist = dist[curr];
                string nextWord = curr;

                for (int i = 0; i < L; ++i) {
                    char orig = nextWord[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == orig) continue;
                        nextWord[i] = c;

                        if (wordSet.count(nextWord)) {
                            if (!dist.count(nextWord)) {
                                dist[nextWord] = currDist + 1;
                                parents[nextWord].push_back(curr);
                                if (nextWord == endWord) {
                                    found = true;
                                } else {
                                    q.push(nextWord);
                                }
                            } else if (dist[nextWord] == currDist + 1) {
                                parents[nextWord].push_back(curr);
                            }
                        }
                    }
                    nextWord[i] = orig;
                }
            }
        }

        if (!found) return {};

        // Phase 2: Backtrack from endWord to beginWord
        vector<vector<string>> res;
        vector<string> path = {endWord};
        dfs(endWord, beginWord, parents, path, res);
        return res;
    }

private:
    void dfs(const string& word, const string& beginWord,
             unordered_map<string, vector<string>>& parents,
             vector<string>& path, vector<vector<string>>& res) {
        if (word == beginWord) {
            vector<string> validPath = path;
            reverse(validPath.begin(), validPath.end());
            res.push_back(move(validPath));
            return;
        }
        for (const string& p : parents[word]) {
            path.push_back(p);
            dfs(p, beginWord, parents, path, res);
            path.pop_back();
        }
    }
};