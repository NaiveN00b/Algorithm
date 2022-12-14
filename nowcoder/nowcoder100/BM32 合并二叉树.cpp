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
     * @param t1 TreeNodeš▒╗ 
     * @param t2 TreeNodeš▒╗ 
     * @return TreeNodeš▒╗
     */
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // write code here
        if(t1 == NULL) return t2;
        if(t2 == NULL) return t1;
        TreeNode *t = new TreeNode(t1->val + t2->val);
        t->left = mergeTrees(t1->left,t2->left);
        t->right = mergeTrees(t1->right,t2->right);
        return t;
        
    }
};