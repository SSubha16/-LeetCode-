class Solution {
    public int totalNumbers(int[] digits) {
        int[] count = new int[10];
        for (int d : digits) {
            count[d]++;
        }

        int total = 0;

        // Check every 3-digit even number
        for (int num = 100; num < 1000; num += 2) {
            int[] currentCount = new int[10];
            int temp = num;

            while (temp > 0) {
                currentCount[temp % 10]++;
                temp /= 10;
            }

            // Verify if num can be formed from the input digits
            boolean canForm = true;
            for (int i = 0; i < 10; i++) {
                if (currentCount[i] > count[i]) {
                    canForm = false;
                    break;
                }
            }

            if (canForm) {
                total++;
            }
        }

        return total;
    }
}