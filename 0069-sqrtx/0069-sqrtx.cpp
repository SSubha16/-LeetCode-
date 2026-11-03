class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        int left = 1, right = x;
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Using division (mid <= x / mid) avoids 32-bit integer overflow
            if (mid <= x / mid) {
                ans = mid;        // mid is a valid candidate
                left = mid + 1;   // try to find a larger value
            } else {
                right = mid - 1;  // mid*mid is too large
            }
        }
        
        return ans;
    }
};