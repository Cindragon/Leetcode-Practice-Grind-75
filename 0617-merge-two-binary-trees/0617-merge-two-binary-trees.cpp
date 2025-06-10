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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL) return root2;
        if(root2==NULL) return root1;
        root1->val+=root2->val; //中
        root1->left=mergeTrees(root1->left, root2->left);    //左
        root1->right=mergeTrees(root1->right, root2->right); //右
        return root1;
    }
};
/*
使用前序遍歷來合併二元樹(中左右)，並且直接修改root1
終止條件為 如果遇到root1==NULL 回傳root2，反之亦然(因為兩棵樹的順序是一起遍歷的)
接著處理中，如果root1跟root2都不為NULL root1的值等於roo1+root2
然後左右子樹就再用遞迴的方式來建構
最後回傳root1(因為我們已經直接修改了)
*/