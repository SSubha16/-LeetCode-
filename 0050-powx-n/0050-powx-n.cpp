class Solution {
public:
    double myPow(double x, int n) {
        // Cast to long long to prevent integer overflow when negating INT_MIN (-2^31)
        long long exp = n;
        
        if (exp < 0) {
            x = 1.0 / x;
            exp = -exp;
        }
        
        double result = 1.0;
        double current_product = x;
        
        while (exp > 0) {
            // If the current bit is set, multiply the result
            if (exp % 2 == 1) {
                result *= current_product;
            }
            // Square the base and shift the exponent
            current_product *= current_product;
            exp /= 2;
        }
        
        return result;
    }
};