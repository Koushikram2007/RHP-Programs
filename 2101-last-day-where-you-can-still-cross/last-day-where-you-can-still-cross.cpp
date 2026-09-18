class Solution {
public:
    int find(vector<int>& ldr, int i){
        if (ldr[i]==i){
            return i;
        }
        return ldr[i]=find(ldr,ldr[i]);
    } 
    void union_set(vector<int>& ldr,int n1,int n2){
        ldr[find(ldr,n2)]=find(ldr,n1);
    }
    int latestDayToCross(int R, int C, vector<vector<int>>& cells) {
        vector<int> ldr(R*C+2);
        for (int i=0;i<R*C+2;i++){
            ldr[i]=i;
        }
        int d[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
        int days=0;
        vector<bool> water(R*C+2,false);
        for (vector<int> cell:cells){
            int row=cell[0]-1;int col=cell[1]-1;
            water[row*C+col+1]=true;
            for (int i=0;i<8;i++){
                int ar=row+d[i][0],ac=col+d[i][1];
                if (ar>=0 && ar<R && ac>=0 && ac<C && water[ar*C+ac+1]){
                    union_set(ldr,row*C+col+1,ar*C+ac+1);
                }
            }
            if (col==0) union_set(ldr,0,row*C+col+1);
            if (col==C-1) union_set(ldr,R*C+1,row*C+col+1);
            if (find(ldr,0)==find(ldr,R*C+1)) return days;
            days++;
        }
        return days;
    }
};