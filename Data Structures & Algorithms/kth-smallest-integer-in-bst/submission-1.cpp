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
    int Inorder(TreeNode*root,int k,int &cnt){
        if(root==NULL){
            return -1;
        }
        int left=Inorder(root->left,k,cnt);
        if(left!=-1) return left;
        cnt++;
        if(cnt==k) return root->val;
        return Inorder(root->right,k,cnt);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        return Inorder(root,k,cnt);
    }
};
