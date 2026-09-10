import java.util.*;

class Solution {
    static class UnionFind {
        int[] parent;

        public UnionFind(int n) {
            parent = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        public int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        }

        public void union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                parent[rootX] = rootY;
            }
        }
    }

    public int minimumHammingDistance(int[] source, int[] target, int[][] allowedSwaps) {
        int n = source.length;
        UnionFind uf = new UnionFind(n);

        // Union connected indices
        for (int[] swap : allowedSwaps) {
            uf.union(swap[0], swap[1]);
        }

        // Group frequencies of source elements by their component root
        Map<Integer, Map<Integer, Integer>> componentCounts = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int root = uf.find(i);
            componentCounts.putIfAbsent(root, new HashMap<>());
            Map<Integer, Integer> countMap = componentCounts.get(root);
            countMap.put(source[i], countMap.getOrDefault(source[i], 0) + 1);
        }

        int hammingDistance = 0;

        // Check if target[i] can be satisfied by its component
        for (int i = 0; i < n; i++) {
            int root = uf.find(i);
            Map<Integer, Integer> countMap = componentCounts.get(root);
            int targetVal = target[i];

            if (countMap.getOrDefault(targetVal, 0) > 0) {
                countMap.put(targetVal, countMap.get(targetVal) - 1);
            } else {
                hammingDistance++;
            }
        }

        return hammingDistance;
    }
}