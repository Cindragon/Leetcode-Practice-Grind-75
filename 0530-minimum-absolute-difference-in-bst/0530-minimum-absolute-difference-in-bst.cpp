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
            result=min(result, root->val-pre->val);
        }
        pre=root;
        Traversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        Traversal(root);
        return result;
    }
};

/*
一樣用中序遍歷的方式
透過自定義函數來遍歷整棵樹
還有result作為INT最大值來比較
並且加入pre指針來比較根節點與前一個節點相減的值
如果pre不等於NULL的時候
result就會是min(result, 相減值)
最後再回傳result
*/