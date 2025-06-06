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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL&&root->right==NULL) return 0;
        int leftnums=sumOfLeftLeaves(root->left);//左
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL){
            leftnums=root->left->val;
        }
        int rightnums=sumOfLeftLeaves(root->right);//右
        int sum=leftnums+rightnums; //中
        return sum;
    }
};

/*
解法：
- 使用後序遍歷（左 -> 右 -> 中）
- 遇到空節點 return 0
- 遞迴遍歷左右子樹，記錄左葉子的總和
- 額外處理：如果左子節點是葉子（無左右子），就加上它的值

*/