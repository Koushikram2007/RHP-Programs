class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string res="";
        for (int i=0;i<s.length();i++){
            if (cnt==0){
                if (s[i]=='('){
                    cnt++;
                }
                else if (s[i]==')'){
                    cnt--;
                }

            }
            else{
                if (s[i]=='('){
                    cnt++;
                }
                else if (s[i]==')'){
                    cnt--;
                }
                if (cnt!=0)
                    res+=s[i];
            }
        }
        return res;
    }
};