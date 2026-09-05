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
    TreeNode*findRoot(TreeNode*root,TreeNode*subRoot){
        if(root==NULL) return NULL;
        TreeNode*left=findRoot(root->left,subRoot);
        TreeNode*right=findRoot(root->right,subRoot);
        if(root->val==subRoot->val && isSame(root, subRoot)) return root;
        if(left) return left;
        if(right) return right;
        return NULL;
    }
    bool isSame(TreeNode*p,TreeNode*q){
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val!=q->val) return false;
        return isSame(p->left,q->left) && isSame(p->right,q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        TreeNode*node=findRoot(root,subRoot);
        return isSame(node,subRoot);
    }
};
