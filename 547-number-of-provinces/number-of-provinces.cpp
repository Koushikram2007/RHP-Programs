class Solution {
public:
    int find(vector<int>& ldr,int node){
        if (ldr[node]==node){
            return node;
        }
        return ldr[node]=find(ldr,ldr[node]);
    }
    void union_set(vector<int>& ldr,int lt,int rt){
        ldr[find(ldr,lt)]=find(ldr,rt);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N=isConnected.size();
        vector<int> ldr(N,0);
        for (int i=0;i<N;i++){
            ldr[i]=i;
        }
        for (int r=0;r<N;r++){
            for (int c=r+1;c<N;c++){
                if (isConnected[r][c]==1){
                    union_set(ldr,r,c);
                }
            }
        }
        int count=0;
        for (int node=0;node<N;node++){
            if (ldr[node]==node){
                count++;
            }
        }
        return count;
    }
};