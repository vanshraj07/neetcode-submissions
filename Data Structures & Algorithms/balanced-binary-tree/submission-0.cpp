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
private:
    int findHeight(TreeNode* root,int &diff){
        if(root==NULL) return 0;
        int lh=findHeight(root->left,diff);
        int rh=findHeight(root->right,diff);
        diff=max(diff,abs(lh-rh));
        return 1+max(lh,rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        int diff=0;
        findHeight(root,diff);
        if(diff>1) return false;
        return true;
    }
};
