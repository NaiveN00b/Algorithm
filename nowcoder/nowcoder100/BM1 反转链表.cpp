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
    ListNode* ReverseList(ListNode* pHead) {
		if(pHead == NULL || pHead->next == NULL) return pHead; 
		ListNode *p = pHead, *q = pHead->next;
		p->next = NULL;
		while(q != NULL){
			ListNode *r = q->next;
			q->next = p;
			p = q;
			q = r;
		}
		pHead = p;
		return pHead;
    }
};
