/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
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
};