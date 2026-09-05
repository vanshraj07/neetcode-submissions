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
    int func(TreeNode*root,int &maxi){
        if(root==NULL){
            return 0;
        }
        int lsum=max(0,func(root->left,maxi));
        int rsum=max(0,func(root->right,maxi));
        maxi=max(maxi,root->val+lsum+rsum);
        return root->val+max(lsum,rsum);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int maxi=INT_MIN;
        func(root,maxi);
        return maxi;
    }
};
