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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int leftHeight=maxDepth(root->left);
        int rightHeight=maxDepth(root->right);
        int Height=1+max(leftHeight, rightHeight);
        return Height;
    }
};
/*
用後序遍歷求二叉樹的根節點高度(也就是這棵樹的深度)
先求左子樹，再求右子樹
然後節點的深度為：1（自己這一層） + 左右子樹的最大高度
*/