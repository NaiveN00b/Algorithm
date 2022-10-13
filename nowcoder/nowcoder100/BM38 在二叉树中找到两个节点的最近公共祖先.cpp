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
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    TreeNode* commonAnc(TreeNode* cur,int o1,int o2){
        if(cur == NULL) return cur;
        if(cur->val == o1 || cur->val == o2) return cur;
        TreeNode* l = commonAnc(cur->left,o1,o2);
        TreeNode* r = commonAnc(cur->right,o1,o2);
        if(l == NULL) return r;
        if(r == NULL) return l;
        return cur;
    }
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        TreeNode* node = commonAnc(root,o1,o2);
        return node->val;

    }
};