/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	TreeNode *pre;
	void dfs(TreeNode* root){
		if(root == NULL) return;
		//中序遍历
		dfs(root->left);
		root->left = pre;
		if(pre) pre->right = root;
		pre = root;
		dfs(root->right);

	}
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(pRootOfTree == NULL) return pRootOfTree;
		TreeNode *p = pRootOfTree;
		while(p->left != NULL) p = p->left;
		dfs(pRootOfTree);
		return p;
    }
};
