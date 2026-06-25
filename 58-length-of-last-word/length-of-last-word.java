class Solution {
    public int lengthOfLastWord(String s) {
        int count=0;
        String str=s.trim();
        String Str=new StringBuilder(str).reverse().toString();
        for (char c:Str.toCharArray()){
            if (c==' '){
                return count;
            }
            else{
                count++;
            }
        }
        return count;
    }
}