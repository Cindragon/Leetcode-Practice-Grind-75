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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL) return NULL;
        if(root->val<low){
            TreeNode* right=trimBST(root->right, low, high);
            return right;
        }
        if(root->val>high){
            TreeNode* left=trimBST(root->left, low, high);
            return left;
        }
        root->left=trimBST(root->left, low, high);
        root->right=trimBST(root->right, low, high);
        return root;
    }
};

/*
根據指定的範圍 [low, high]，修剪二元搜尋樹（BST），
使得所有節點的值都位於該範圍內，並保持原本的結構（即仍然是 BST）。

如果值小於 low，表示整棵左子樹都不可能在範圍內（因為是 BST），
   所以只需要遞迴處理右子樹並回傳結果。

反之若是其值大於high，表示整棵右子樹都不可能在範圍內，
   所以只需要遞迴處理左子樹並回傳結果。

若目前節點的值位於範圍內，則遞迴處理左右子樹，更新左右子節點後回傳目前節點。
最後回傳root
*/