class Solution {
public:
    int getHeight(TreeNode *root){
		if(root == NULL) return 0;
		int l = getHeight(root->left);
		int r = getHeight(root->right);
		return max(l,r) + 1;
	}
	bool IsBalanced_Solution(TreeNode* root) {
		if(root == NULL) return true;
		bool l = IsBalanced_Solution(root->left);
		bool r = IsBalanced_Solution(root->right);
		if(abs(getHeight(root->left) - getHeight(root->right)) <= 1 && l && r) return true;
		else return false;
	}
};