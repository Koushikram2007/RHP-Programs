/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int f_idx = -1,l_idx = -1;
        int preval=head.val;
        ListNode curr = head.next;
        int idx=1;
        int minDis=Integer.MAX_VALUE;
        while (curr.next!=null){
            int currval=curr.val,nextval=curr.next.val;
            boolean maxima = currval>preval && currval>nextval;
            boolean minima = currval<preval && currval<nextval;
            if (minima || maxima){
                if (f_idx==-1){
                    f_idx=idx;
                }
                else{
                    minDis = Math.min(minDis,idx - l_idx);
                }
                l_idx=idx;
            }
            preval=curr.val;
            curr=curr.next;
            idx++;
        }
        if (f_idx==-1 || f_idx==l_idx){
            return new int[]{-1,-1};
        }
        int maxDis = l_idx - f_idx;
        return new int[]{minDis,maxDis};
    }
}