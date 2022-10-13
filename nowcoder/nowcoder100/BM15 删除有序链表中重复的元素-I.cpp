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
        ListNode *pre = head,*p = head->next;
        while(p != NULL){
            if(p->val != pre->val){
                p = p->next;
                pre = pre->next;
            }else{
                while(p != NULL && p->val == pre->val){
                    p = p->next;
                }
                pre->next = p;
            }
        }
        return head;
    }
};