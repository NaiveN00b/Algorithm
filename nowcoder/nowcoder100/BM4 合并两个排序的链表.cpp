/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        //连个头结点都没有，傻逼题也不说的
		if(pHead1 == NULL) return pHead2;
		else if(pHead2 == NULL) return pHead1;
        ListNode *p = pHead1;
		ListNode *q = pHead2;
		ListNode *dummy = new ListNode(0);
		ListNode *r = dummy;
		// r->next = NULL;
		while(p != NULL && q!=NULL){
			if(p->val < q->val){
				r->next = p;
				r = p;
				p = p->next;
			}else{
				r->next = q;
				r = q;
				q = q->next;
			}
		}
		if(p != NULL) r->next = p;
		if(q != NULL) r->next = q;
		return dummy->next;

    }
};
