class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        int N=s.length(),ones=0,lt=0;
        String ans="";
        for (int rt=0;rt<N;rt++){
            if (s.charAt(rt)=='1'){
                ones++;
            }
            while (ones>k){
                if (s.charAt(lt)=='1'){
                    ones--;
                    lt++;
                }
            }
            if (ones==k){
                while (s.charAt(lt)=='0'){
                    lt++;
                }
                String curr = s.substring(lt,rt+1);
                if (ans.isEmpty() || curr.length()<ans.length() || (curr.length()==ans.length() && curr.compareTo(ans)<0)){
                    ans=curr;
                }
            }
        }
        return ans;
    }
}