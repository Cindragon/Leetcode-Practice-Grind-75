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
使用遞迴方式，依據 BST（二元搜尋樹）的性質尋找最近公共祖先（Lowest Common Ancestor, LCA）

1. 終止條件：
   - 如果 root 為 NULL，表示走到底還沒找到，直接回傳 NULL。
   - 如果 root 等於 p 或 q，代表找到了其中一個節點，回傳該節點。

2. 遞迴邏輯：
   - 若 root 的值比 p 和 q 的值都大，代表它們都在左子樹中，往左找。
   - 若 root 的值比 p 和 q 的值都小，代表它們都在右子樹中，往右找。
   - 否則代表 p 和 q 分別位於 root 的左右兩側（或一個就是 root），此時 root 就是最近公共祖先。

注意：
- 這裡假設 p 和 q 一定存在於 BST 中，且值不相等。
- 利用了 BST 的性質：左子樹所有節點值 < root，右子樹所有節點值 > root。
*/