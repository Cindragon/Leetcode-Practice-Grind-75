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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(p==NULL&&q==NULL) return true;
       if(p==NULL||q==NULL) return false;
       if(p->val!=q->val) return false;

       bool leftTree=isSameTree(p->left, q->left);
       bool rightTree=isSameTree(p->right, q->right);
       return leftTree&&rightTree; 
    }
};

/*
比對時有三個終止條件
1. p 跟 q 都為 NULL (遍歷到子樹終點) return true
2. p 或 q 為 NULL (不相等) return false
3. p 跟 q 的值不相等 return false
接下來把遍歷左右子樹後
若左右子樹都相同，則整棵樹相同，回傳 `true`，否則回傳 `false`。
不需要在值相等時提早 `return true`，因為還需要遞迴比較整棵樹的所有節點。
若提早回傳 `true`，會中斷遞迴，導致邏輯錯誤。
*/