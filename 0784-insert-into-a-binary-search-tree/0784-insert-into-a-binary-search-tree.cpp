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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            return new TreeNode(val);
        }
        if(val<root->val){
            root->left=insertIntoBST(root->left, val);
        }
        if(val>root->val){
            root->right=insertIntoBST(root->right, val);
        }
        return root;
    }
};

/*
找到適當的位置將val插入
終止條件為 在root==NULL時
說明找到了插入位置，此時return 一個新的TreeNode
接下來要再接回去
透過BST的特性，藉由比較值的大小來判斷要往左還是往右
再將新的節點插入到左子樹或是右子樹
最後return root
*/