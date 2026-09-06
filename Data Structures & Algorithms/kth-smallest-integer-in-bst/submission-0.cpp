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
    void Inorder(TreeNode*root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        Inorder(root->left,ans);
        ans.push_back(root->val);
        Inorder(root->right,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return 0;
        vector<int>ans;
        Inorder(root,ans);
        return ans[k-1];
    }
};
