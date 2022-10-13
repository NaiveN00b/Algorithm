#include <stdbool.h>
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

/**
 * 
 * @param head ListNode类 
 * @return bool布尔型
 */
bool hasCycle(struct ListNode* head ) {
    // write code here
    if(head == NULL || head->next == NULL) return false;
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
        if(fast->next == NULL)  return false;
        else fast = fast->next;
        if(fast == slow) return true;
    }
    return false;
}