class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int N=nums.size();
        vector<int> mini(N);
        mini[N-1]=nums[N-1];
        for (int i=N-2;i>=0;i--){
            mini[i]=min(mini[i+1],nums[i]);
        }
        int maxi=nums[0];
        int min_idx=N;
        for (int i=0;i<N;i++){
            maxi=max(maxi,nums[i]);
            if (maxi-mini[i]<=k){
                min_idx=min(min_idx,i);
            }
        }
        return min_idx==N ? -1 : min_idx;
    }
};