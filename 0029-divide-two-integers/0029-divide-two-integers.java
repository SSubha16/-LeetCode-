class Solution {
    public int divide(int dividend, int divisor) {
        // Handle 32-bit integer overflow edge case:
        // Integer.MIN_VALUE / -1 = 2147483648, which exceeds Integer.MAX_VALUE (2147483647).
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        // Determine the sign of the quotient
        boolean negative = (dividend < 0) ^ (divisor < 0);

        // Convert both numbers to positive long values to prevent overflow on Math.abs(Integer.MIN_VALUE)
        long dvd = Math.abs((long) dividend);
        long dvs = Math.abs((long) divisor);

        int quotient = 0;

        // Exponential subtraction using bit shifts
        while (dvd >= dvs) {
            long tempDvs = dvs;
            int multiple = 1;

            // Double the divisor as long as it fits inside the remaining dividend
            while (dvd >= (tempDvs << 1)) {
                tempDvs <<= 1;
                multiple <<= 1;
            }

            dvd -= tempDvs;
            quotient += multiple;
        }

        return negative ? -quotient : quotient;
    }
}