class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int N=nums1.size();
        int pno=*min_element(nums1.begin(),nums1.end());
        string parity=(pno%2==0)?"Even":"Odd"; 
        if (parity=="Even"){
            for (int i=0;i<N;i++){
                if (nums1[i]%2!=0){
                    nums1[i]-=pno;
                    if (nums1[i]%2!=0){
                        return false;
                    }
                }
            }
        }
        else{
            for (int i=0;i<N;i++){
                if (nums1[i]%2==0){
                    nums1[i]-=pno;
                    if (nums1[i]%2==0){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};