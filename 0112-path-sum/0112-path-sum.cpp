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
        }
        bool left, right;
        left=hasPathSum(root->left, targetSum-root->val);
        right=hasPathSum(root->right, targetSum-root->val);
        return left||right;
    }
};
/*
用遞迴法的方式
使用前序遍歷(中左右)
檢查如果是到葉子節點時，如果targetSum等於root的值(相減之後為0)
代表有一條路徑相加之後可以找到這個target
接著左右子樹遞迴
每次都傳入target-root->val的值
最後return left||right(其中有一條是true就可以)
*/