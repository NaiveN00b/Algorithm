/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @param p int整型 
     * @param q int整型 
     * @return int整型
     */
    TreeNode* Traversal(TreeNode *cur,int p,int q){
        if(cur == NULL) return NULL;
        if(cur->val > p && cur->val > q){
            TreeNode *left = Traversal(cur->left, p, q);
            if(left) return left;
        }
        if(cur->val < p && cur->val < q){
            TreeNode *right = Traversal(cur->right, p, q);
            if(right) return right;
        }
        return cur;
    }
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        // write code here
        TreeNode *node = Traversal(root, p, q);
        return node->val;
    }
};