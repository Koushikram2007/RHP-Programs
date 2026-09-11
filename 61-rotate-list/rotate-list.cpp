/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        int cnt = 1;
        ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
            cnt++;
        }
        k = k % cnt;
        if (k == 0) {
            return head;
        }
        int moves = cnt - k;
        ListNode* p = head;
        while (--moves && p->next != NULL) {
            p = p->next;
        }
        ListNode* head2 = p->next;
        ListNode* l = head2;
        while (l->next != NULL) {
            l = l->next;
        }
        l->next = head;
        p->next = NULL;
        return head2;
    }
};