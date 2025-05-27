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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int leftHeight=minDepth(root->left);
        int rightHeight=minDepth(root->right);
        if(root->left==NULL&&root->right!=NULL) return 1+rightHeight;
        else if(root->left!=NULL&&root->right==NULL) return 1+leftHeight;
        else
            return 1+min(leftHeight, rightHeight);
    }
};
/*
跟求最大深度一樣，用後序遍歷的方式
但是要考慮的有時候會有左子樹或右子樹為空的情況
所以不能直接求左右子樹的最小值+1
*/