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
        TreeNode* root=new TreeNode();
        if(root1!=NULL&&root2!=NULL){   //中
            root->val=root1->val+root2->val;
        }
        root->left=mergeTrees(root1->left, root2->left);    //左
        root->right=mergeTrees(root1->right, root2->right); //右
        return root;
    }
};
/*
使用前序遍歷來合併二元樹(中左右)
終止條件為 如果遇到root1==NULL 回傳root2，反之亦然(因為兩棵樹的順序是一起遍歷的)
接著處理中，如果root1跟root2都不為NULL root的值等於兩者相加
然後左右子樹就再用遞迴的方式來建構
最後回傳root
*/