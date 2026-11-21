from collections import deque, defaultdict
from typing import List

class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        word_set = set(wordList)
        if endWord not in word_set:
            return []
        
        # Phase 1: BFS to find shortest distances and record parent links
        parents = defaultdict(list)
        dist = {beginWord: 0}
        queue = deque([beginWord])
        found = False
        word_len = len(beginWord)
        
        while queue and not found:
            for _ in range(len(queue)):
                curr = queue.popleft()
                curr_dist = dist[curr]
                
                for i in range(word_len):
                    for c in 'abcdefghijklmnopqrstuvwxyz':
                        if c == curr[i]:
                            continue
                        nxt = curr[:i] + c + curr[i+1:]
                        
                        if nxt in word_set:
                            if nxt not in dist:
                                dist[nxt] = curr_dist + 1
                                parents[nxt].append(curr)
                                if nxt == endWord:
                                    found = True
                                else:
                                    queue.append(nxt)
                            elif dist[nxt] == curr_dist + 1:
                                parents[nxt].append(curr)
                                
        if not found:
            return []
        
        # Phase 2: Backtrack from endWord to beginWord
        res = []
        path = [endWord]
        
        def dfs(word: str):
            if word == beginWord:
                res.append(path[::-1])
                return
            for p in parents[word]:
                path.append(p)
                dfs(p)
                path.pop()
                
        dfs(endWord)
        return res