/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        if(head == NULL || head->next == NULL) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy,*p = head,*q = head->next;
        while(q != NULL){
            if(p->val != q->val){
                pre = pre->next;
                p = p->next;
                q = q->next;
            }else{
                while(q != NULL && p->val == q->val){
                    p = p->next;
                    q = q->next;
                }
                if(q != NULL){
                    p = p->next;
                    q = q->next;
                    pre->next = p;
                }else pre->next = q;    
            }
        }
        return dummy->next;
    }
};