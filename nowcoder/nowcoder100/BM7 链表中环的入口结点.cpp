
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if(pHead->next == NULL) return NULL;
        ListNode *fast = pHead,*slow = pHead;
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
            if(fast->next == NULL) return NULL;
            else fast = fast->next;
            if(fast == slow){
                fast = pHead;
                while(fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                break;
            }
        }
        return fast;

    }
};