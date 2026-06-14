class Solution {
    public int findTheLongestBalancedSubstring(String s) {
        int n = s.length();
        int maxLen = 0;
        int i = 0;

        while (i < n) {
            int c0 = 0;
            int c1 = 0;

            while (i < n && s.charAt(i) == '0') {
                c0++;
                i++;
            }

            while (i < n && s.charAt(i) == '1') {
                c1++;
                i++;
            }

            maxLen = Math.max(maxLen, 2 * Math.min(c0, c1));
        }

        return maxLen;
    }
}