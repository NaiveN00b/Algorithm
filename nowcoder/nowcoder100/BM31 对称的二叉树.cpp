
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool compare(TreeNode *left,TreeNode *right){
        if((left == NULL && right != NULL) || (left != NULL && right == NULL)) return false;
        else if(left == NULL && right == NULL) return true;
        else if(left->val != right->val) return false;
        
        bool outside = compare(left->left,right->right);
        bool inside = compare(left->right, right->left);
        return outside && inside;
    }
    bool isSymmetrical(TreeNode* pRoot) {
        if(pRoot == NULL) return true;
        return compare(pRoot->left,pRoot->right);
    }

};