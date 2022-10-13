
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 求二叉树的右视图
     * @param xianxu int整型vector 先序遍历
     * @param zhongxu int整型vector 中序遍历
     * @return int整型vector
     */
    unordered_map<int,int> pos;
    TreeNode* reConstruct(vector<int> pre,vector<int> vin,int preL,int preR,int inL,int inR){
        if(preL > preR) return NULL;
        int val = pre[preL];
        int k = pos[val];
        int llen = k - inL;
        TreeNode *root = new TreeNode(val);
        root->left = reConstruct(pre,vin,preL+1,preL+llen,inL,k-1);
        root->right = reConstruct(pre,vin,preL+llen+1,preR,k+1,inR);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int n = pre.size();
        for(int i = 0;i < n;i++){
            pos[vin[i]] = i;
        }
        return reConstruct(pre,vin,0,n-1,0,n-1);
    }
    vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
        // write code here
        vector<int> ans;
        if(xianxu.size() == 0) return ans;
        TreeNode *root = reConstructBinaryTree(xianxu,zhongxu);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                TreeNode *node = q.front();
                q.pop();
                if(i == size - 1) ans.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }
};