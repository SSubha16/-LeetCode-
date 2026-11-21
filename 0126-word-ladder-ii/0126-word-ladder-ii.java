import java.util.*;

class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>(wordList);
        List<List<String>> res = new ArrayList<>();
        if (!wordSet.contains(endWord)) return res;

        // Phase 1: BFS to find shortest distances and record parent links
        Map<String, List<String>> parents = new HashMap<>();
        Map<String, Integer> dist = new HashMap<>();
        Queue<String> queue = new ArrayDeque<>();

        dist.put(beginWord, 0);
        queue.offer(beginWord);
        boolean found = false;
        int L = beginWord.length();

        while (!queue.isEmpty() && !found) {
            int size = queue.size();
            for (int k = 0; k < size; k++) {
                String curr = queue.poll();
                int currDist = dist.get(curr);
                char[] chars = curr.toCharArray();

                for (int i = 0; i < L; i++) {
                    char orig = chars[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == orig) continue;
                        chars[i] = c;
                        String nextWord = new String(chars);

                        if (wordSet.contains(nextWord)) {
                            if (!dist.containsKey(nextWord)) {
                                dist.put(nextWord, currDist + 1);
                                parents.computeIfAbsent(nextWord, x -> new ArrayList<>()).add(curr);
                                if (nextWord.equals(endWord)) {
                                    found = true;
                                } else {
                                    queue.offer(nextWord);
                                }
                            } else if (dist.get(nextWord) == currDist + 1) {
                                parents.get(nextWord).add(curr);
                            }
                        }
                    }
                    chars[i] = orig;
                }
            }
        }

        if (!found) return res;

        // Phase 2: Backtrack from endWord to beginWord
        List<String> path = new ArrayList<>();
        path.add(endWord);
        dfs(endWord, beginWord, parents, path, res);
        return res;
    }

    private void dfs(String word, String beginWord, Map<String, List<String>> parents,
                     List<String> path, List<List<String>> res) {
        if (word.equals(beginWord)) {
            List<String> validPath = new ArrayList<>(path);
            Collections.reverse(validPath);
            res.add(validPath);
            return;
        }
        for (String p : parents.getOrDefault(word, Collections.emptyList())) {
            path.add(p);
            dfs(p, beginWord, parents, path, res);
            path.remove(path.size() - 1);
        }
    }
}