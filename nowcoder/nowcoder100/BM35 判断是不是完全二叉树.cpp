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
     * @return bool布尔型
     */
    bool isCompleteTree(TreeNode* root) {
        // write code here
        if(root == NULL) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;//判断本层是否出现过NULL
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                TreeNode *node = q.front();
                q.pop();
                if(node != NULL){
                    if(flag) return false;
                    q.push(node->left);
                    q.push(node->right);
                }else if(!flag) flag = true;
            }
        }
        return true;
    }
};