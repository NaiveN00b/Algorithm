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
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy,*cur = head,*p = head;
        int num = 0;
        while(p != NULL){
            num++;
            p = p->next;
        }
        ListNode *temp;
        for(int i = 0;i < num/k;i++){
            for(int j = 1;j < k;j++){
                temp = cur->next;
                cur->next = temp->next;
                temp->next = pre->next;
                pre->next = temp;
            }
            pre = cur;
            cur = cur->next;
        }
        return dummy->next;
        }
};