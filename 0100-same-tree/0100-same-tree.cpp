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
不需要加上值相等回傳true，會讓整個遞迴提早結束
比對時有三個終止條件
1. p 跟 q 都為 NULL (遍歷到子樹終點) return true
2. p 或 q 為 NULL (不相等) return false
3. p 跟 q 的值不相等 return false
接下來把遍歷左右子樹後，將布林值進行運算回傳
*/