class Solution {
    public int missingMultiple(int[] nums, int k) {
        boolean[] bool = new boolean[101];
        for (int i=0;i<nums.length;i++){
            if (nums[i]%k==0){
                bool[nums[i]/k]=true;
            }
        }
        for (int i=1;i<101;i++){
            if (!bool[i]==true){
                return i*k;
            }
        }
        return 101*k;
    }
}