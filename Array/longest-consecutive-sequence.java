import java.util.*;

class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> hashSet = new HashSet<Integer>();

        for (int i : nums) {
            hashSet.add(i);
        }

        int longestSet = 0;

        for (int i : nums) {
            if (!hashSet.contains(i - 1)) {
                int currentNum = i;
                int count = 1;

                while (hashSet.contains(currentNum + 1)) {
                    currentNum += 1;
                    count += 1;
                }
                longestSet = Math.max(longestSet, count);
            }
        }
        return longestSet;
    }
}

// TC- O(N)
// SC-O(N) in java set->O(N) but in C++ set->O(1)