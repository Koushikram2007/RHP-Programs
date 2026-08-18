class Solution {
    public int largestInteger(int[] nums, int k) {
        HashMap<Integer, Integer> count = new HashMap<>();
    
        int n = nums.length;
        for (int i = 0; i <= n - k; i++) {
            HashSet<Integer> seen = new HashSet<>();

            for (int j = i; j < i + k; j++) {
                seen.add(nums[j]);
            }

            for (int x : seen) {
                count.put(x, count.getOrDefault(x, 0) + 1);
            }
        }
        int ans = -1;
        for (int x : count.keySet()) {
            if (count.get(x) == 1) {
                ans = Math.max(ans, x);
            }
        }
        return ans;
    }
}