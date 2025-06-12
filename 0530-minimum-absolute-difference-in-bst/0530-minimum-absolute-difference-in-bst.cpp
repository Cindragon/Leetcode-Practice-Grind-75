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
    TreeNode* pre=NULL;
    int result=INT_MAX;
    void Traversal(TreeNode* root){
        if(root==NULL) return;
        Traversal(root->left);
        if(pre!=NULL){
            result=min(result, abs(root->val-pre->val));
        }
        pre=root;
        Traversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        Traversal(root);
        return result;
    }
};