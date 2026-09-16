import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> grayCode(int n) {
        int total = 1 << n; // 2^n
        List<Integer> result = new ArrayList<>(total);

        for (int i = 0; i < total; i++) {
            // Standard binary-to-Gray-code formula: i ^ (i >> 1)
            result.add(i ^ (i >> 1));
        }

        return result;
    }
}