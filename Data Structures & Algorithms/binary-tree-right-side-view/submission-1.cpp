/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int h(TreeNode* root){
        if(!root)return 0;
        return max(h(root->left), h(root->right)) + 1;
    }
    vector<int> v;
    int mx_lvl = 0;
    void dfs(TreeNode* root, int level){
        if(!root)return;
        int r = h(root->right);
        int l = h(root->left);
        if(r >= l){
            if(level > mx_lvl)v.push_back(root->val);
            mx_lvl = max(level,mx_lvl);
            dfs(root->right,level+1);
        }
        else{
            if(level > mx_lvl)v.push_back(root->val);
            mx_lvl = max(level,mx_lvl);
            dfs(root->right, level+1);
            dfs(root->left, level+1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        v.push_back(root->val);
        dfs(root, 0);
        return v;
    }
};
