class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for (int i=0;i<nums.size();i++){
            int req=target-nums[i];
            if (map.find(req)!=map.end()){
                return {map[req],i};
            }
            map[nums[i]]=i;
        }
        return {-1,-1};
    }
};