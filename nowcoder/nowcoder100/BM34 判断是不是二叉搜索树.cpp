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
    void dfs(struct TreeNode* root,vector<int>& path){
        if(root == NULL) return;
        dfs(root->left,path);
        path.push_back(root->val);
        dfs(root->right,path);
    }
    bool isValidBST(struct TreeNode* root ) {
        // write code here
        vector<int> path;
        dfs(root,path);
        for(int i = 0;i < path.size() -1 ;i++){
            if(path[i] > path[i+1]) return false;
        }
        return true;
    }
};