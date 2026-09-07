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
    TreeNode*makeTree(int preStart,int preEnd,vector<int>&preorder,
    int inStart,int inEnd,vector<int>&inorder,unordered_map<int,int>&mpp){
        if (preStart>preEnd || inStart>inEnd) {
            return NULL;
        }
        TreeNode*curr=new TreeNode(preorder[preStart]);
        int ind=mpp[preorder[preStart]];
        int numsleft=ind-inStart;
        curr->left=makeTree(preStart+1,preStart+numsleft,preorder,
        inStart,ind-1,inorder,mpp);
        curr->right=makeTree(preStart+numsleft+1,preEnd,preorder,
        ind+1,inEnd,inorder,mpp);
        return curr;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return makeTree(0,preorder.size()-1,preorder,
        0,inorder.size()-1,inorder,mpp);
    }
};
