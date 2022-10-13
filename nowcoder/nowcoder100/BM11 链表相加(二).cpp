/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* reverseL(ListNode* head){
        if(head == NULL) return head;
        ListNode *cur = head,*pre = NULL;
        while(cur != NULL){
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        ListNode *p = reverseL(head1);
        ListNode *q = reverseL(head2);
        int carry = 0;
        ListNode *ans = new ListNode(-1);
        ListNode *r = ans;
        while(p != NULL || q != NULL || carry != 0){
            int val1 = p == NULL? 0 : p->val;
            int val2 = q == NULL? 0 : q->val;
            ListNode *now = new ListNode((val1+val2+carry)%10);
            carry = max((val1 + val2 +carry) / 10,0);
            r->next = now;
            r = now;
            if(p)   p = p->next;
            if(q)   q = q->next;
        }
        return reverseL(ans->next);
    }
};