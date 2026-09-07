class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> uwords;
        for (string w:words){
            uwords.insert(w);
        }
        unordered_set<string> ans;
        for (int i=0;i<words.size();i++){
            int N=words[i].length();
            int *dp = new int[N+1];
            dp[0]=1;
            for (int si=0;si<N;si++){
                if (dp[si]!=1) continue;
                for (int ei=si;ei<N;ei++){
                    if (ei-si+1<N && uwords.count(words[i].substr(si,ei-si+1))){
                        dp[ei+1]=1;
                    }
                }
                if (dp[N]==1){
                    ans.insert(words[i]);
                }
            } 
        }
        vector<string> fin;
        for (string w:ans){
            fin.push_back(w);
        }
        return fin;
    }
};