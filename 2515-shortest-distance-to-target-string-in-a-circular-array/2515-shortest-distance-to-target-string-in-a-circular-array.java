class Solution {
    public int closestTarget(String[] words, String target, int startIndex) {
        int n = words.length;
        int minDistance = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            if (words[i].equals(target)) {
                int linearDist = Math.abs(i - startIndex);
                int circularDist = Math.min(linearDist, n - linearDist);
                minDistance = Math.min(minDistance, circularDist);

                if (minDistance == 0) {
                    return 0;
                }
            }
        }

        return minDistance == Integer.MAX_VALUE ? -1 : minDistance;
    }
}