
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> ans;
        if(pRoot == NULL) return ans;
        vector<int> path;
        queue<TreeNode*> q;
        q.push(pRoot);
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size;i++){
                TreeNode *node = q.front();
                q.pop();
                path.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level % 2 == 0)  reverse(path.begin(),path.end());
            ans.push_back(path);
            path.clear();
            level += 1;
        }
        return ans;
    }
    
};