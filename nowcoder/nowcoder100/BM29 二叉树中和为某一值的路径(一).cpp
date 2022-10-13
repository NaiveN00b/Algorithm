/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    bool dfs(TreeNode* root,int target){
        if(root->left == NULL && root->right == NULL){
            if(target == 0) return true;
            else return false;
        }
        if(root->left){
            if(dfs(root->left,target-root->left->val)) return true;
        }
        if(root->right){
            if(dfs(root->right,target-root->right->val)) return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        // write code here
        if(root == NULL) return false;
        return dfs(root,sum-root->val);
    }
};