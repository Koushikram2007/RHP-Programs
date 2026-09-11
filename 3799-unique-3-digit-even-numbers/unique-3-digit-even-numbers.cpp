class Solution {
public:
    int totalNumbers(vector<int>& d) {
        int N=d.size();
        set<int> unique;
        for (int i=0;i<N;i++){
            if (d[i]==0){
                continue;
            }
            for (int j=0;j<N;j++){
                for (int k=0;k<N;k++){
                    if (i!=j && j!=k && i!=k){
                        int num=d[i]*100+d[j]*10+d[k];
                        if (num%2==0){
                            unique.insert(num);
                        }
                    }
                }
            }
        }
        return unique.size();
    }
};