import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> current = new ArrayList<>();
        
        for (int num : nums) {
            current.add(num);
        }
        
        backtrack(0, current, result);
        return result;
    }

    private void backtrack(int start, List<Integer> nums, List<List<Integer>> result) {
        if (start == nums.size()) {
            result.add(new ArrayList<>(nums));
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            Collections.swap(nums, start, i);
            backtrack(start + 1, nums, result);
            Collections.swap(nums, start, i); // Backtrack
        }
    }
}