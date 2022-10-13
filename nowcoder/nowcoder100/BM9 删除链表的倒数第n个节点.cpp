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
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // write code here
        ListNode *dummy = new ListNode(-1);
        dummy->next = head; 
        ListNode *fast = dummy,*slow = dummy;
        for(int i = 0;i < n;i++){
            fast = fast->next;
        }
        // //由于题目说n一定有效，因此只需保证此时fast!=NULL，此时为NULL说明删除了第一个结点
        // if(fast == NULL) return head->next;
        while(fast->next != NULL){//找到倒数n+1个结点
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};