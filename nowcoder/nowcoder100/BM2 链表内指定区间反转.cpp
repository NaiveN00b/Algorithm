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
	 * @param m int整型 
	 * @param n int整型 
	 * @return ListNode类
	 */
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		// write code here
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *pre = dummy,*cur = head;
		for(int i = 1;i < m;i++){
			pre = cur;
			cur = cur->next;
		}
		for(int i = m;i < n ;i++){
			ListNode *temp = cur->next;
			cur->next = temp->next;
			temp->next = pre->next;
			pre->next = temp;
		}
		return dummy->next;
		
	}
};
