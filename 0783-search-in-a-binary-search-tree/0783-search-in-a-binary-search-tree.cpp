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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL||root->val==val) return root;
        if(root->val>val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
        return NULL;
    }
};
/*
運用二元搜索樹的特性來找回傳值
如果大於val往右邊找，小於往左邊找
最後都沒有就return NULL
*/