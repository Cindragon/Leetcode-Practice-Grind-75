/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL|root==p|root==q) return root;
        if(root->val>p->val&&root->val>q->val){
            TreeNode* left=lowestCommonAncestor(root->left, p, q);
            if(left!=NULL) return left;
        }
        if(root->val<p->val&&root->val<q->val){
            TreeNode* right=lowestCommonAncestor(root->right, p, q);
            if(right!=NULL) return right;
        }
        return root;
    }
};

/*
用後序遍歷的方式來遍歷整顆樹(遞迴)
一開始先設置終止條件(如果root==NULL或是root=p or q ) return root
代表找到了最近共同祖先
接著設置遞迴條件(左右中)
設置左邊跟右邊
最後中間就看如果左右都不為空則回傳root
如果其中一邊為空(若只在一邊找到，那就回傳該邊的結果。)
*/