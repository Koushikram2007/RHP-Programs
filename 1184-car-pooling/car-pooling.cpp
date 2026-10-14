class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> Km(1001,0);
        int md = 0;
        for (int i=0;i<trips.size();i++){
            int np = trips[i][0];
            Km[trips[i][1]]+=np;
            Km[trips[i][2]]-=np;
            md=max(md,trips[i][2]);
        }
        for (int i=1;i<=md;i++){
            Km[i]+=Km[i-1];
        }
        for (int i=0;i<md+1;i++){
            if (Km[i]>capacity){
                return false;
            }
        }
        return true;
    }
};