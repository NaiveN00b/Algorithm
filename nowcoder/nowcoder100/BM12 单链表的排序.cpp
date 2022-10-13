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
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* merge(ListNode *head1,ListNode *head2){
        //合并两个有序链表
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        ListNode *head = new ListNode(-1);
        ListNode *r = head;
        while(head1 && head2){
            if(head1->val < head2->val){
                r->next = head1;
                head1 = head1->next;
            }else{
                r->next = head2;
                head2 = head2->next;
            }
            r = r->next;
        }
        //不可能两个同时为NULL
        if(head1) r->next = head1;
        if(head2) r->next = head2;
        return head->next;
    }
    ListNode* sortInList(ListNode* head) {
        // write code here
        if(head == NULL || head->next == NULL) return head;
        ListNode *l = head,*mid = head->next,*r = head->next->next;
        while(r != NULL && r->next != NULL){
            l = l->next;
            mid = mid->next;
            r = r->next->next;
        }
        l->next = NULL;
        //l,mid,r将链表二分，第一段表头为head，第二段表头为mid
        return merge(sortInList(head),sortInList(mid));
    }
};