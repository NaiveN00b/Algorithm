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
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        ListNode *p = pHead1,*q = pHead2;
		while(p != q){
			if(p) p = p->next;
			else p = pHead2;
			if(q) q = q->next;
			else q = pHead1;
		}
		return p;
    }
};
