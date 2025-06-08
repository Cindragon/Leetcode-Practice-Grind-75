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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL){
            if(targetSum==root->val) return 1;
            else return 0;
        }
        bool left, right;
        left=hasPathSum(root->left, targetSum-root->val);
        right=hasPathSum(root->right, targetSum-root->val);
        return left||right;
    }
};