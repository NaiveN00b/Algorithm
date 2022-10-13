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
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        // write code here
        if(head == NULL || head->next == NULL) return true; 
        ListNode *p = head;
        int num = 0;
        while(p){
            num += 1;
            p = p->next;
        }
        p = head;
        bool flag = false;
        if(num % 2 == 1) flag = true;
        int ans[num/2];
        for(int i = 0;i < num/2;i++){
            ans[i] = p->val;
            p = p->next;
        }
        if(flag) p = p->next;
        for(int i = num/2 - 1;i >= 0;i--){
            if(ans[i] != p->val) return false;
            p = p->next;
        }
        return true;

    }
};