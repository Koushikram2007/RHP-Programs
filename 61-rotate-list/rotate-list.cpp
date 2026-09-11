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
        ListNode* tail = head;
        while (--moves && tail->next != NULL) {
            tail = tail->next;
        }
        ListNode* nhead = tail->next;
        ListNode* ntail = nhead;
        while (ntail->next != NULL) {
            ntail = ntail->next;
        }
        ntail->next = head;
        tail->next = NULL;
        return nhead;
    }
};